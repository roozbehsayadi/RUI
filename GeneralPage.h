#ifndef __GENERAL_PAGE_H
#define __GENERAL_PAGE_H

#include <string>

#include "layout/BaseLayout.h"
#include "monitor/RuiMonitor.h"

class GeneralPage {

public:
  // Arguments:
  // - Caption of the window
  GeneralPage(std::string);

  BaseLayout &getGrid();

private:
  RuiMonitor monitor;

  BaseLayout grid;
};

#endif //__GENERAL_PAGE_H