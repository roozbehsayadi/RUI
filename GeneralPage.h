#ifndef __GENERAL_PAGE_H
#define __GENERAL_PAGE_H

#include <string>

#include "layout/Container.h"
#include "monitor/RuiMonitor.h"
#include "utils/Rect.h"

class GeneralPage {

public:
  // Arguments:
  // - Caption of the window
  GeneralPage(std::string);

  void render(RuiMonitor &monitor, const Rect &rect) {
    grid.render(monitor, rect);
  }

  // This function handles all SDL events
  // and returns on SDL_QUIT event.
  void handleEvents();

  RuiMonitor &getMonitor() { return this->monitor; }
  Container &getGrid() { return this->grid; }

private:
  RuiMonitor monitor;

  Container grid;
};

#endif //__GENERAL_PAGE_H
