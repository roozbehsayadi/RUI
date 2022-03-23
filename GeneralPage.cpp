
#include "GeneralPage.h"

GeneralPage::GeneralPage(std::string caption) {
  monitor.setCaption(caption);

  grid.setWidth(100.0);
  grid.setHeight(100.0);
}

void GeneralPage::render(RuiMonitor &monitor, const Rect &rect) {
  grid.render(monitor, rect);
}

RuiMonitor &GeneralPage::getMonitor() { return this->monitor; }

BaseLayout &GeneralPage::getGrid() { return this->grid; }
