#ifndef __BUTTON_WIDGET_H
#define __BUTTON_WIDGET_H

#include "BaseWidget.h"
#include "monitor/RuiMonitor.h"
#include "utils/Rect.h"

class ButtonWidget : public BaseWidget {
public:
  ButtonWidget() { type = WIDGET_BUTTON; }

  virtual void draw(RuiMonitor &monitor, const Rect &rect,
                    const Color &color) override {
    monitor.drawRectangle(rect, color);
  };
};

#endif
