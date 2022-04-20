#ifndef __ROW_LAYOUT_H
#define __ROW_LAYOUT_H

#include "Container.h"
#include "monitor/RuiMonitor.h"
#include "utils/Geometry.h"
#include "utils/Rect.h"

class RowLayout : public Container {
public:
  RowLayout(const std::string &slug) : RowLayout(slug, 0.0, 0.0) {}
  RowLayout(const std::string &slug, double width, double height,
            double xPad = 0.0, double yPad = 0.0, double xMargin = 0.0,
            double yMargin = 0.0)
      : Container(slug, width, height, xPad, yPad, xMargin, yMargin) {
    type = LAYOUT_ROW;
  }

  virtual bool handleScroll(int, int, int, int) override;

  virtual void render(RuiMonitor &) const override;
};

#endif // __ROW_LAYOUT_H
