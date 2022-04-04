#ifndef __CONTAINER_H
#define __CONTAINER_H

#include "BaseLayout.h"
#include "monitor/RuiMonitor.h"

class Container : public BaseLayout {
public:
  Container() : Container(0.0, 0.0, 0.0, 0.0) {}
  Container(double width, double height, double xPad = 0.0, double yPad = 0.0,
            double xMargin = 0.0, double yMargin = 0.0)
      : BaseLayout(width, height, xPad, yPad, xMargin, yMargin) {
    type = LAYOUT_UNKNOWN;
  }

  void addChild(BaseLayout *child) { grid.push_back(child); }

  virtual void render(RuiMonitor &, const Rect &) const override;

protected:
  std::vector<BaseLayout *> grid;
};

#endif // __CONTAINER_H