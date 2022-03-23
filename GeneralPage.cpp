
#include "GeneralPage.h"

GeneralPage::GeneralPage(std::string caption) {
  monitor.setCaption(caption);

  auto monitorSize = monitor.getMonitorSize();
  grid.setWidth(monitorSize.first);
  grid.setHeight(monitorSize.second);
}

BaseLayout &GeneralPage::getGrid() { return this->grid; }
