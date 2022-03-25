
#include "BaseLayout.h"

#include <iostream>

void BaseLayout::render(RuiMonitor &monitor, const Rect &rect) const {
  monitor.drawRectangle(rect, {255, 0, 0});
  for (auto child : grid) {
    Rect temp{rect.x + rect.w * xPad + rect.w * child->getXMargin(),
              rect.y + rect.h * yPad + rect.h * child->getYMargin(),
              rect.w * child->getWidth(), rect.h * child->getHeight()};
    child->render(monitor, temp);
  }
}
