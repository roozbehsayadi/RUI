
#include "GeneralPage.h"

GeneralPage::GeneralPage(std::string caption) {
  monitor.setCaption(caption);

  grid.setWidth(100.0);
  grid.setHeight(100.0);
}

void GeneralPage::handleEvents() {
  SDL_Event event;
  bool quit = false;
  while (!quit) {
    while (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT)
        quit = true;
    }
  }
}
