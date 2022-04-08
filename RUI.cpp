
#include "RUI.h"

void RUI::start() {
  render();
  handleEvents();
}

void RUI::handleEvents() {
  bool quit = false;
  SDL_Event event;
  while (!quit) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        quit = true;
      for (auto i = 0u; i < windows.size(); i++) {
        windows.at(i)->handleEvents(event);
      }
    }
    render();
    if (isAllWindowsClosed())
      quit = true;
  }
}

void RUI::render() {
  for (auto *window : windows) {
    window->render();
    window->update();
  }
}

bool RUI::isAllWindowsClosed() const {
  bool allWindowsClosed = true;
  for (auto *window : windows)
    if (window->isShown()) {
      return false;
    }
  return true;
}
