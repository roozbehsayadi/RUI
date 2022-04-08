
#include "ColumnLayout.h"

#include <iostream>

void ColumnLayout::render(RuiMonitor &monitor) const {
  monitor.drawRectangle(positionPixel, {255, 0, 0});
  double currentY = this->getYPad() * positionPixel.h;
  for (auto i = 0u; i < children.size(); i++) {
    auto cell = children.at(i);
    const Rect cellRect = {
        positionPixel.x + positionPixel.w * cell->getXMargin() +
            positionPixel.w * this->getXPad(),
        positionPixel.y + currentY + positionPixel.h * cell->getYMargin() +
            positionPixel.h * this->getYPad(),
        cell->getWidth() * positionPixel.w,
        cell->getHeight() * positionPixel.h};
    cell->setPositionPixel(cellRect);
    monitor.drawRectangle(cellRect, {255, 0, 0});
    currentY += cellRect.h + positionPixel.h * cell->getYMargin() * 2 +
                positionPixel.h * this->getYPad();
    cell->render(monitor);
  }
}
