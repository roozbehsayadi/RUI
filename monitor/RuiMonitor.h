#ifndef __RUI_MONITOR_H
#define __RUI_MONITOR_H

#include <iostream>
#include <map>
#include <string>

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

#include "utils/Color.h"
#include "utils/Rect.h"

class GeneralPage;

class RuiMonitor {

  friend class GeneralPage;

public:
  // Create a window with title "window"
  RuiMonitor();
  // Arguments:
  // - Caption of the window.
  explicit RuiMonitor(const std::string &);
  ~RuiMonitor();

  void setCaption(const std::string &);

  std::pair<int, int> getMonitorSize() const;

  void close();

  void clear();
  void update();
  void delay(int);

  void drawRectangle(const Rect &, const Color &);
  void drawText(const Rect &, const Color &, const std::string &);

private:
  SDL_Window *window;
  SDL_Renderer *renderer;

  std::map<int, TTF_Font *> font;

  bool initializeFonts();
  int getFontSizeToFit(const Rect &, const std::string &);
};

#endif // __RUI_MONITOR_H
