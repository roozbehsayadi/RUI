
#include "ColumnLayout.h"

#include <iostream>

void ColumnLayout::render(RuiMonitor &monitor, const Rect &rect) const {
  monitor.drawRectangle(rect, {255, 0, 0});
  double currentY = this->getYPad() * rect.h;
  for (auto i = 0u; i < children.size(); i++) {
    auto cell = children.at(i);
    const Rect cellRect = {
        rect.x + rect.w * cell->getXMargin() + rect.w * this->getXPad(),
        rect.y + currentY + rect.h * cell->getYMargin() +
            rect.h * this->getYPad(),
        cell->getWidth() * rect.w, cell->getHeight() * rect.h};
    monitor.drawRectangle(cellRect, {255, 0, 0});
    currentY +=
        cellRect.h + rect.h * cell->getYMargin() * 2 + rect.h * this->getYPad();
    cell->render(monitor, cellRect);
  }
}
