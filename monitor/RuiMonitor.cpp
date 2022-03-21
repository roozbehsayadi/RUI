
#include "RuiMonitor.h"

#include <iostream>

RuiMonitor::RuiMonitor() : RuiMonitor("window") {}

RuiMonitor::RuiMonitor(const std::string &windowCaption) {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    std::cerr << "SDL Could not be initialized. Error: " << SDL_GetError()
              << "\n";
  else {
    window = SDL_CreateWindow(windowCaption.c_str(), SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, 0, 0,
                              SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr)
      std::cerr << "Window could not be created. Error: " << SDL_GetError()
                << "\n";
    else {
      renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
      if (renderer == nullptr)
        std::cerr << "Renderer could not be initialized. Error: "
                  << SDL_GetError() << "\n";
    }
  }
}

RuiMonitor::~RuiMonitor() {
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void RuiMonitor::setCaption(const std::string &caption) {
  SDL_SetWindowTitle(window, caption.c_str());
}
