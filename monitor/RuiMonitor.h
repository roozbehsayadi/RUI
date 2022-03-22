#ifndef __RUI_MONITOR_H
#define __RUI_MONITOR_H

#include <string>
#include <utility>

#include "SDL2/SDL.h"

#include "utils/Rect.h"
#include "utils/Color.h"

class RuiMonitor {

public:
  // Create a window with title "window"
  RuiMonitor();
  // Arguments:
  // - Caption of the window.
  explicit RuiMonitor(const std::string &);
  ~RuiMonitor();

  void setCaption(const std::string &);

  void clear();
  void update();

  void drawRectangle(const Rect &, const Color &);

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
};

#endif // __RUI_MONITOR_H
