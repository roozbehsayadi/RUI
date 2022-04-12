
#include "RowLayout.h"

void RowLayout::render(RuiMonitor &monitor) const {
  monitor.drawRectangle(positionPixel, {255, 0, 0});
  double currentX = this->getXPad() * positionPixel.w;
  for (auto i = 0u; i < children.size(); i++) {
    auto cell = children.at(i);
    const Rect cellRect = {
        positionPixel.x + currentX + positionPixel.w * cell->getXMargin() +
            positionPixel.w * this->getXPad(),
        positionPixel.y + positionPixel.h * cell->getYMargin() +
            positionPixel.h * this->getYPad(),
        cell->getWidth() * positionPixel.w,
        cell->getHeight() * positionPixel.h};
    cell->setPositionPixel(cellRect);
    monitor.drawRectangle(cellRect, {255, 0, 0});
    currentX += cellRect.w + positionPixel.w * cell->getXMargin() * 2 +
                positionPixel.w * this->getXPad() * 2;
    cell->render(monitor);
  }
}
