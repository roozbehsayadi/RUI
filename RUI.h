#ifndef __RUI_H
#define __RUI_H

#include <vector>

#include "window/GeneralPage.h"

class RUI {

public:
  void addWindow(GeneralPage *page) { windows.push_back(page); }
  void start();

private:
  void handleEvents();
  void render();

  bool isAllWindowsClosed() const;

  // TODO handle without pointers
  std::vector<GeneralPage *> windows;
};

#endif // __RUI_H
