#ifndef __ROW_LAYOUT_H
#define __ROW_LAYOUT_H

#include "BaseLayout.h"

class RowLayout : public BaseLayout {
public:
  RowLayout() : RowLayout(0.0, 0.0) {}
  RowLayout(double width, double height, double xPad = 0.0, double yPad = 0.0,
            double xMargin = 0.0, double yMargin = 0.0)
      : BaseLayout(width, height, xPad, yPad, xMargin, yMargin) {
    type = LayoutType::ROW;
  }
};

#endif // __ROW_LAYOUT_H
