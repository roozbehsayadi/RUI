#ifndef __RUI_H
#define __RUI_H

#include <vector>

#include "SDL2/SDL.h"

#include "window/GeneralPage.h"

class RUI {

public:
  void addWindow(GeneralPage *page) { windows.push_back(page); }
  bool handleEvents();
  void render();

private:
  bool isAllWindowsClosed() const;

  // TODO handle without pointers
  std::vector<GeneralPage *> windows;
};

#endif // __RUI_H
