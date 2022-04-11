
#include "RuiMonitor.h"

#include <iostream>

RuiMonitor::RuiMonitor() : RuiMonitor("window") {}

RuiMonitor::RuiMonitor(const std::string &windowCaption) {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cerr << "SDL Could not be initialized. Error: " << SDL_GetError()
              << "\n";
    return;
  }
  if (TTF_Init() == -1) {
    std::cerr << "SDL_ttf could not be initialized. Error: " << SDL_GetError()
              << "\n";
    return;
  }
  if (!this->initializeFonts()) {
    std::cerr << "Could not initialize fonts. Error: " << TTF_GetError()
              << "\n";
    return;
  }
  window =
      SDL_CreateWindow(windowCaption.c_str(), SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    std::cerr << "Window could not be created. Error: " << SDL_GetError()
              << "\n";
    return;
  }
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == nullptr) {
    std::cerr << "Renderer could not be initialized. Error: " << SDL_GetError()
              << "\n";
    return;
  }
}

RuiMonitor::~RuiMonitor() {
  SDL_DestroyWindow(window);
  for (auto it : this->font) {
    TTF_CloseFont(it.second);
  }
  TTF_Quit();
  SDL_Quit();
}

void RuiMonitor::setCaption(const std::string &caption) {
  SDL_SetWindowTitle(window, caption.c_str());
}

std::pair<int, int> RuiMonitor::getMonitorSize() const {
  int w, h;
  SDL_GetWindowSize(window, &w, &h);
  return std::make_pair(w, h);
}

void RuiMonitor::close() { SDL_DestroyWindow(window); }

void RuiMonitor::clear() { SDL_RenderClear(renderer); }

void RuiMonitor::update() { SDL_RenderPresent(renderer); }

void RuiMonitor::delay(int milisecond) { SDL_Delay(milisecond); }

void RuiMonitor::drawRectangle(const Rect &rect, const Color &color) {
  SDL_SetRenderDrawColor(renderer, color.getRed(), color.getGreen(),
                         color.getBlue(), color.getAlpha());
  SDL_FRect temp{float(rect.x), float(rect.y), float(rect.w), float(rect.h)};
  SDL_RenderDrawRectF(renderer, &temp);
}

void RuiMonitor::drawText(const Rect &rect, const Color &color,
                          const std::string &text) {
  SDL_Color temp{color.getRed(), color.getGreen(), color.getBlue(), 255};
  int fontSize = getFontSizeToFit(rect, text);
  SDL_Surface *textSurface =
      TTF_RenderText_Blended(font[fontSize], text.c_str(), temp);
  SDL_Texture *textTexture =
      SDL_CreateTextureFromSurface(renderer, textSurface);
  SDL_Rect targetRect{int(rect.x + fabs(rect.w - textSurface->w) / 2),
                      int(rect.y + fabs(rect.h - textSurface->h) / 2),
                      textSurface->w, textSurface->h};
  SDL_RenderCopy(renderer, textTexture, NULL, &targetRect);
  // TODO Do I need to SDL_DestroyTexture(textTexture)?
  SDL_FreeSurface(textSurface);
}

bool RuiMonitor::initializeFonts() {
  for (int i = 1; i < 100; i++) {
    this->font[i] = TTF_OpenFont("assets/fonts/FreeMono.ttf", i);
    if (this->font[i] == NULL)
      return false;
  }
  return true;
}

int RuiMonitor::getFontSizeToFit(const Rect &rect, const std::string &text) {
  // TODO I don't like the way this function works.
  for (int i = 1; i < 100; i++) {
    auto f = this->font[i];
    int w, h;
    TTF_SizeText(f, text.c_str(), &w, &h);
    if (h > rect.h || w > rect.w)
      return std::max(i - 3, 1);
  }
  return 99;
}
