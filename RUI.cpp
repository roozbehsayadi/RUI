
#include "RUI.h"

#include <iostream>

bool RUI::handleEvents() {
  bool quit = false;
  static SDL_Event event;
  if (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT)
      quit = true;
    for (auto i = 0u; i < windows.size(); i++) {
      windows.at(i)->handleEvents(event);
    }
  }
  if (isAllWindowsClosed())
    quit = true;
  return quit;
}

void RUI::render() {
  for (auto *window : windows) {
    window->clear();
    window->render();
    window->update();
  }
}

bool RUI::isClicked(const std::string &slug) {
  for (auto *window : windows)
    if (window->isClicked(slug))
      return true;
  return false;
}

void RUI::setLayoutHidden(const std::string &slug, bool hidden) {
  for (auto *window : windows)
    if (window->setLayoutHidden(slug, hidden))
      return;
}

void RUI::setEnabledWidget(const std::string &slug, bool enabled) {
  for (auto *window : windows)
    if (window->setEnabledWidget(slug, enabled))
      return;
}

bool RUI::isAllWindowsClosed() const {
  bool allWindowsClosed = true;
  for (auto *window : windows)
    if (window->isShown()) {
      return false;
    }
  return true;
}
