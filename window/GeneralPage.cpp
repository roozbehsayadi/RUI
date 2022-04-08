
#include "GeneralPage.h"

#include <iostream>

GeneralPage::GeneralPage(std::string caption) {
  monitor.setCaption(caption);

  grid.setWidth(100.0);
  grid.setHeight(100.0);

  shown = true;
}

void GeneralPage::handleEvents(SDL_Event &event) {
  if (event.type == SDL_WINDOWEVENT &&
      event.window.windowID == SDL_GetWindowID(monitor.window)) {
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
    }
  }
}
