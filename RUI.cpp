
#include "RUI.h"

#include <iostream>

RUI &RUI::getInstance() {
  static RUI instance;
  return instance;
}

bool RUI::handleEvents() {
  bool quit = false;
  static SDL_Event event;
  windowsToRender.clear();

  if (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      quit = true;
    }
    for (auto it : windows) {
      it.second->handleEvents(event);
      if (RuiSettings::mustRender) {
        windowsToRender.push_back(it.first);
        RuiSettings::mustRender = false;
      }
    }
  }
  if (windows.size() > 1 && isAllWindowsClosed()) {
    quit = true;
  }
  return quit;
}

void RUI::render() {
  if (firstRender) {
    for (auto it : windows) {
      auto window = it.second;
      window->clear();
      window->render();
      window->update();
    }
    firstRender = false;
  } else if (windowsToRender.size() != 0) {
    for (auto slug : windowsToRender) {
      windows[slug]->clear();
      windows[slug]->render();
      windows[slug]->update();
    }
    windowsToRender.clear();
  }
}

SDL_Keycode RUI::getPressedKey(const std::string &pageSlug) {
  if (!windows.contains(pageSlug))
    return SDLK_UNKNOWN;
  return windows.at(pageSlug)->getPressedKey();
}

std::set<SDL_Keymod> RUI::getKeyboardModifiers(const std::string &pageSlug) {
  if (!windows.contains(pageSlug))
    return {};
  return windows.at(pageSlug)->getModifiers();
}

std::pair<std::shared_ptr<BaseWidget>, bool> RUI::getWidget(const std::string &slug) const {
  for (auto it : windows) {
    auto window = it.second;
    auto returnValue = window->getWidget(slug);
    auto widget = returnValue.first;
    auto hidden = returnValue.second;
    if (widget != nullptr)
      return returnValue;
  }
  return std::make_pair(nullptr, false);
}

std::shared_ptr<BaseLayout> RUI::getLayout(const std::string &slug) const {
  for (auto it : windows) {
    auto window = it.second;
    auto returnValue = window->getLayout(slug);
    if (returnValue != nullptr)
      return returnValue;
  }
  return nullptr;
}

bool RUI::isAllWindowsClosed() const {
  bool allWindowsClosed = true;
  for (auto it : windows)
    if (it.second->isShown())
      return false;
  return true;
}
