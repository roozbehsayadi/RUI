
#include "GeneralPage.h"

GeneralPage::GeneralPage(const std::string &slug, const std::string &caption) {
  monitor.setCaption(caption);

  grid = std::make_shared<ColumnLayout>(slug + "__COLUMN", 1.0, 1.0);

  shown = true;
  this->slug = slug;
}

void GeneralPage::render() {
  auto monitorSize = monitor.getMonitorSize();
  Rect monitorRect{0.0, 0.0, double(monitorSize.first), double(monitorSize.second)};
  grid->setPositionPixel(monitorRect);
  grid->render(monitor, monitorRect);
}

void GeneralPage::handleEvents(SDL_Event &event) {
  if (event.window.windowID != SDL_GetWindowID(monitor.window))
    return;
  if (event.type == SDL_WINDOWEVENT) {
    switch (event.window.event) {
    case SDL_WINDOWEVENT_SHOWN:
      shown = true;
      break;

    case SDL_WINDOWEVENT_HIDDEN:
      shown = false;
      break;

    case SDL_WINDOWEVENT_EXPOSED:
      monitor.update();
      break;

    case SDL_WINDOWEVENT_CLOSE:
      SDL_HideWindow(monitor.window);
      break;

    default:
      break;
    }
  } else if (event.type == SDL_MOUSEBUTTONDOWN) {
    grid->handleClick(event.button.x, event.button.y);
  } else if (event.type == SDL_MOUSEMOTION) {
    SDL_GetMouseState(&mouseX, &mouseY);
  } else if (event.type == SDL_MOUSEWHEEL) {
    grid->handleScroll(event.wheel.y, mouseX, mouseY);
  }

  if (grid->hasFocusedWidget()) {
    if (event.type == SDL_TEXTINPUT) {
      grid->handleTextInput(event.text.text[0]);
    }
  }
  if (event.type == SDL_KEYDOWN) {
    auto sym = event.key.keysym.sym;
    if (grid->hasFocusedWidget()) {
      if (sym == SDLK_BACKSPACE)
        grid->handleTextInput(sym);
    } else
      addPressedKey(sym);
  }
}

char GeneralPage::getPressedKey() {
  if (pressedKeys.size() == 0)
    return SDLK_UNKNOWN;
  auto temp = pressedKeys.front();
  pressedKeys.pop();
  return temp;
}

bool GeneralPage::hasPressedKey() { return (pressedKeys.size() != 0); }

std::set<SDL_Keymod> GeneralPage::getModifiers() const {
  static std::set<SDL_Keymod> modifiers;
  this->fillModifiers(modifiers, SDL_GetModState());
  return modifiers;
}

std::pair<std::shared_ptr<BaseWidget>, bool> GeneralPage::getWidget(const std::string &slug) const {
  return grid->getWidget(slug);
}

std::shared_ptr<BaseLayout> GeneralPage::getLayout(const std::string &slug) const { return grid->getLayout(slug); }

void GeneralPage::addPressedKey(SDL_Keycode pressedKey) {
  if (pressedKeys.size() >= 100)
    pressedKeys.pop();
  pressedKeys.push(pressedKey);
}

void GeneralPage::fillModifiers(std::set<SDL_Keymod> &modifiers, SDL_Keymod sdlModifiers) {
  modifiers.clear();
  std::array<SDL_Keymod, 13> allMods{KMOD_NONE, KMOD_LSHIFT, KMOD_RSHIFT,  KMOD_LCTRL, KMOD_RCTRL,
                                     KMOD_LALT, KMOD_RALT,   KMOD_LGUI,    KMOD_RGUI,  KMOD_NUM,
                                     KMOD_CAPS, KMOD_MODE,   KMOD_RESERVED};
  for (auto mod : allMods)
    if (sdlModifiers & mod)
      modifiers.insert(mod);
}
