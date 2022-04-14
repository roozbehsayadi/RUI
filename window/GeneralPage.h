#ifndef __GENERAL_PAGE_H
#define __GENERAL_PAGE_H

#include <string>
#include <utility>

#include "layout/ColumnLayout.h"
#include "layout/Container.h"
#include "monitor/RuiMonitor.h"
#include "utils/Rect.h"
#include "widgets/BaseWidget.h"

class GeneralPage {

public:
  // Arguments:
  // - Slug of the main container
  // - Caption of the window
  GeneralPage(const std::string &, const std::string &);

  void render();
  void clear() { monitor.clear(); }
  void update() { monitor.update(); }

  // This function handles all SDL events
  // and returns on SDL_QUIT event.
  void handleEvents(SDL_Event &);

  std::pair<std::shared_ptr<BaseWidget>, bool>
  getWidget(const std::string &) const;

  bool setLayoutHidden(const std::string &, bool);

  RuiMonitor &getMonitor() { return this->monitor; }
  std::shared_ptr<Container> getGrid() { return this->grid; }

  bool isShown() const { return this->shown; }

private:
  RuiMonitor monitor;

  std::shared_ptr<Container> grid;

  bool shown;
};

#endif //__GENERAL_PAGE_H
