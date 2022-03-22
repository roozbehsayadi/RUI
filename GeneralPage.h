#ifndef __GENERAL_PAGE_H
#define __GENERAL_PAGE_H

#include <string>

#include "monitor/RuiMonitor.h"

class GeneralPage {

public:
  // Arguments:
  // - Caption of the window
  GeneralPage(std::string);

private:
  RuiMonitor monitor;
};

#endif //__GENERAL_PAGE_H
