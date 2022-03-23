
#include "RowLayout.h"

#include <iostream>

void RowLayout::render(RuiMonitor &monitor, const Rect &rect) const {
  monitor.drawRectangle(rect, {255, 0, 0});
  double currentX = this->getXPad() * rect.w;
  for (auto i = 0u; i < grid.size(); i++) {
    auto cell = grid.at(i);
    const Rect cellRect = {
        rect.x + currentX + rect.w * cell->getXMargin() +
            rect.w * this->getXPad(),
        rect.y + rect.h * cell->getYMargin() + rect.h * this->getYPad(),
        cell->getWidth() * rect.w, cell->getHeight() * rect.h};
    monitor.drawRectangle(cellRect, {255, 0, 0});
    currentX += cellRect.w + rect.w * cell->getXMargin() * 2 +
                rect.w * this->getXPad() * 2;
    cell->render(monitor, cellRect);
  }
}
