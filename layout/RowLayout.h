#ifndef __ROW_LAYOUT_H
#define __ROW_LAYOUT_H

#include "Container.h"
#include "monitor/RuiMonitor.h"
#include "utils/Rect.h"

class RowLayout : public Container {
public:
  RowLayout() : RowLayout(0.0, 0.0) {}
  RowLayout(double width, double height, double xPad = 0.0, double yPad = 0.0,
            double xMargin = 0.0, double yMargin = 0.0)
      : Container(width, height, xPad, yPad, xMargin, yMargin) {
    type = LAYOUT_ROW;
  }

  virtual void render(RuiMonitor &, const Rect &) const override;
};

#endif // __ROW_LAYOUT_H
