
#include "RuiMonitor.h"

RuiMonitor::RuiMonitor() : RuiMonitor("window") {}

RuiMonitor::RuiMonitor(const std::string &windowCaption) {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cerr << "SDL Could not be initialized. Error: " << SDL_GetError() << "\n";
    return;
  }
  if (TTF_Init() == -1) {
    std::cerr << "SDL_ttf could not be initialized. Error: " << SDL_GetError() << "\n";
    return;
  }
  if (!this->initializeFonts()) {
    std::cerr << "Could not initialize fonts. Error: " << TTF_GetError() << "\n";
    return;
  }
  window = SDL_CreateWindow(windowCaption.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768,
                            SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    std::cerr << "Window could not be created. Error: " << SDL_GetError() << "\n";
    return;
  }
  int imageFlags = IMG_INIT_JPG | IMG_INIT_PNG;
  if (IMG_Init(imageFlags) != imageFlags) {
    std::cerr << "Could not initialize SDL_image. Error: " << IMG_GetError() << "\n";
    return;
  }
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == nullptr) {
    std::cerr << "Renderer could not be initialized. Error: " << SDL_GetError() << "\n";
    return;
  }
}

RuiMonitor::~RuiMonitor() {
  SDL_DestroyWindow(window);
  for (auto it : this->font) {
    TTF_CloseFont(it.second);
  }
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}

void RuiMonitor::setCaption(const std::string &caption) { SDL_SetWindowTitle(window, caption.c_str()); }

std::pair<int, int> RuiMonitor::getMonitorSize() const {
  int w, h;
  SDL_GetWindowSize(window, &w, &h);
  return std::make_pair(w, h);
}

void RuiMonitor::close() { SDL_DestroyWindow(window); }

void RuiMonitor::clear(Color color) {
  SDL_SetRenderDrawColor(renderer, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
  SDL_RenderClear(renderer);
}

void RuiMonitor::update() { SDL_RenderPresent(renderer); }

void RuiMonitor::delay(int milisecond) { SDL_Delay(milisecond); }

void RuiMonitor::drawRectangle(const Rect &rect, const Color &color) {
  SDL_SetRenderDrawColor(renderer, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
  SDL_FRect temp = rect;
  SDL_RenderDrawRectF(renderer, &temp);
}

void RuiMonitor::drawBox(const Rect &rect, const Color &color) {
  SDL_SetRenderDrawColor(renderer, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
  SDL_FRect temp = rect;
  SDL_RenderFillRectF(renderer, &temp);
}

// TODO refactor maybe?
// TODO UPDATE: definetely
void RuiMonitor::drawText(const Rect &rect, const Rect &showableArea, const Color &color, const std::string &text,
                          FontFitMethod fitMethod) {
  if (text == "")
    return;
  SDL_Color temp{color.getRed(), color.getGreen(), color.getBlue(), 255};
  int fontSize = getFontSizeToFit(rect, text, fitMethod);
  SDL_Surface *textSurface = TTF_RenderText_Blended(font[fontSize], text.c_str(), temp);
  SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

  Rect targetRect;
  if (fitMethod == FONT_FIT_BOTH)
    targetRect = {rect.x + fabs(rect.w - textSurface->w) / 2, rect.y + fabs(rect.h - textSurface->h) / 2,
                  double(textSurface->w), double(textSurface->h)};
  else if (fitMethod == FONT_FIT_VERTICAL) {
    if (textSurface->w > rect.w)
      targetRect = {rect.x + rect.w - textSurface->w, rect.y, double(textSurface->w), double(textSurface->h)};
    else
      targetRect = {rect.x, rect.y, double(textSurface->w), double(textSurface->h)};
  }

  auto trimmedTargetRect = Geometry::trimRect(targetRect, showableArea).first;

  SDL_Rect trimmedSDLRect = {int(trimmedTargetRect.x - targetRect.x), int(trimmedTargetRect.y - targetRect.y),
                             int(trimmedTargetRect.w), int(trimmedTargetRect.h)};
  SDL_Rect targetSDLRect = trimmedTargetRect;
  SDL_RenderCopy(renderer, textTexture, &trimmedSDLRect, &targetSDLRect);
  SDL_DestroyTexture(textTexture);
  SDL_FreeSurface(textSurface);
}

// if rect's width or height is negative, the image's width/ height will be its original.
// original image's width and height will be returned. Negative values indicate errors.
std::pair<double, double> RuiMonitor::drawImage(const Rect &rect, const Rect &showableArea, SDL_Texture *&texture,
                                                const std::string &imagePath) {
  if (texture == nullptr) {
    texture = IMG_LoadTexture(renderer, imagePath.c_str());
    if (!texture) {
      std::cerr << "Could not open image " + imagePath + ". Error: " << IMG_GetError() << "\n";
      return {-1.0, -1.0};
    }
  }
  SDL_Point temp;
  SDL_QueryTexture(texture, NULL, NULL, &temp.x, &temp.y);

  Rect processedRect = rect;
  if (rect.w < 0)
    processedRect.w = temp.x;
  if (rect.h < 0)
    processedRect.h = temp.y;

  auto trimmedTargetRect = Geometry::trimRect(processedRect, showableArea).first;

  SDL_Rect trimmedSDLRect = {
      int((trimmedTargetRect.x - processedRect.x) * temp.x / processedRect.w),
      int((trimmedTargetRect.y - processedRect.y) * temp.y / processedRect.h),
      int((trimmedTargetRect.w * temp.x) / processedRect.w),
      int((trimmedTargetRect.h * temp.y) / processedRect.h),
  };
  SDL_Rect targetSDLRect = trimmedTargetRect;
  SDL_RenderCopy(renderer, texture, &trimmedSDLRect, &targetSDLRect);

  return {processedRect.w, processedRect.h};
}

bool RuiMonitor::initializeFonts() {
  for (int i = 1; i < 100; i++) {
    this->font[i] = TTF_OpenFont("assets/fonts/FreeMonoBold.ttf", i);
    if (this->font[i] == NULL)
      return false;
  }
  return true;
}

int RuiMonitor::getFontSizeToFit(const Rect &rect, const std::string &text, FontFitMethod fitMethod) {
  // TODO I don't like the way this function works.
  for (int i = 1; i < 100; i++) {
    auto f = this->font[i];
    int w, h;
    TTF_SizeText(f, text.c_str(), &w, &h);
    if (fitMethod == FONT_FIT_BOTH && (h > rect.h || w > rect.w) || (fitMethod == FONT_FIT_VERTICAL && (h > rect.h)))
      return std::max(i - 3, 1);
  }
  return 99;
}
