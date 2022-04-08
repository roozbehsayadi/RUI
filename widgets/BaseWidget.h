#ifndef __BASE_WIDGET_H
#define __BASE_WIDGET_H

#include <string>
#include <utility>
#include <vector>

#include "monitor/RuiMonitor.h"
#include "utils/Color.h"
#include "utils/Rect.h"

enum WidgetType {
  WIDGET_UNKNOWN,
  WIDGET_BUTTON,
};

class BaseWidget {
public:
  BaseWidget() { type = WIDGET_UNKNOWN; }

  virtual void draw(RuiMonitor &, const Color &) = 0;
  virtual void handleClick(int, int) = 0;

  void setPositionPixel(const Rect &positionPixel) {
    this->positionPixel = positionPixel;
  }


protected:
  WidgetType type;

  Rect positionPixel;
};

#endif // __BASE_WIDGET_H
