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

  virtual void draw(RuiMonitor &, const Rect &, const Color &) = 0;

protected:
  WidgetType type;
};

#endif // __BASE_WIDGET_H
