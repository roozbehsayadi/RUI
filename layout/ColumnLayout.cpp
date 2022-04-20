
#include "ColumnLayout.h"

void ColumnLayout::render(RuiMonitor &monitor) const {
  if (!this->hidden) {
    monitor.drawRectangle(positionPixel, {255, 0, 0});
    double currentY = 0;
    for (auto i = 0u; i < children.size(); i++) {
      auto cell = children.at(i);
      if (cell->isHidden())
        continue;
      const Rect cellRect = {
          positionPixel.x + positionPixel.w * cell->getXMargin() +
              positionPixel.w * this->getXPad(),
          positionPixel.y + currentY + positionPixel.h * cell->getYMargin() +
              positionPixel.h * this->getYPad(),
          cell->getWidth() * positionPixel.w,
          cell->getHeight() * positionPixel.h};
      cell->setPositionPixel(cellRect);
      currentY += cellRect.h + positionPixel.h * cell->getYMargin() * 2 +
                  positionPixel.h * this->getYPad() * 2;
      auto temp = this->trimRect(cellRect);
      if (temp.second) {
        monitor.drawRectangle(temp.first, {255, 0, 0});
        cell->render(monitor);
      }
    }
  }
}
