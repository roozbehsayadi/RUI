
#include "RUI.h"

#include <iostream>

bool RUI::handleEvents() {
  bool quit = false;
  static SDL_Event event;
  if (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      quit = true;
    }
    for (auto i = 0u; i < windows.size(); i++) {
      windows.at(i)->handleEvents(event);
    }
  }
  if (windows.size() > 1 && isAllWindowsClosed()) {
    quit = true;
  }
  return quit;
}

void RUI::render() {
  for (auto *window : windows) {
    window->clear();
    window->render();
    window->update();
  }
}

std::pair<std::shared_ptr<BaseWidget>, bool> RUI::getWidget(const std::string &slug) const {
  for (auto *window : windows) {
    auto returnValue = window->getWidget(slug);
    auto widget = returnValue.first;
    auto hidden = returnValue.second;
    if (widget != nullptr)
      return returnValue;
  }
  return std::make_pair(nullptr, false);
}

std::shared_ptr<BaseLayout> RUI::getLayout(const std::string &slug) const {
  for (auto *window : windows) {
    auto returnValue = window->getLayout(slug);
    if (returnValue != nullptr)
      return returnValue;
  }
  return nullptr;
}

bool RUI::isAllWindowsClosed() const {
  bool allWindowsClosed = true;
  for (auto *window : windows)
    if (window->isShown())
      return false;
  return true;
}
