#ifndef __COLUMN_LAYOUT_H
#define __COLUMN_LAYOUT_H

#include "BaseLayout.h"
#include "monitor/RuiMonitor.h"
#include "utils/Rect.h"

class ColumnLayout : public BaseLayout {
public:
  ColumnLayout() : ColumnLayout(0.0, 0.0) {}
  ColumnLayout(double width, double height, double xPad = 0.0,
               double yPad = 0.0, double xMargin = 0.0, double yMargin = 0.0)
      : BaseLayout(width, height, xPad, yPad, xMargin, yMargin) {
    type = LAYOUT_COLUMN;
  }

  virtual void render(RuiMonitor &, const Rect &) const override;
};

#endif // __COLUMN_LAYOUT_H
