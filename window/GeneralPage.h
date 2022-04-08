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

  void render() {
    auto monitorSize = monitor.getMonitorSize();
    grid.render(monitor, {0.0, 0.0, double(monitorSize.first),
                          double(monitorSize.second)});
  }

  void update() { monitor.update(); }

  // This function handles all SDL events
  // and returns on SDL_QUIT event.
  void handleEvents(SDL_Event &);

  RuiMonitor &getMonitor() { return this->monitor; }
  Container &getGrid() { return this->grid; }

  bool isShown() const { return this->shown; }

private:
  RuiMonitor monitor;

  Container grid;

  bool shown;
};

#endif //__GENERAL_PAGE_H
