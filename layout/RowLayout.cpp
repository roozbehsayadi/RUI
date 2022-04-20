
#include "RowLayout.h"

bool RowLayout::handleScroll(int wheelX, int wheelY, int mouseX, int mouseY) {
  bool somethingAffected =
      this->Container::handleScroll(wheelX, wheelY, mouseX, mouseY);
  if (!somethingAffected && children.size() != 0 &&
      Geometry::isPointInsideRect(mouseX, mouseY, positionPixel)) {
    this->initialDistance += wheelX;
    somethingAffected = true;
  }
  return somethingAffected;
}

void RowLayout::render(RuiMonitor &monitor) const {
  if (!this->hidden) {
    monitor.drawRectangle(positionPixel, {255, 0, 0});
    double currentX = this->initialDistance;
    for (auto i = 0u; i < children.size(); i++) {
      auto cell = children.at(i);
      if (cell->isHidden())
        continue;
      const Rect cellRect = {
          positionPixel.x + currentX + positionPixel.w * cell->getXMargin() +
              positionPixel.w * this->getXPad(),
          positionPixel.y + positionPixel.h * cell->getYMargin() +
              positionPixel.h * this->getYPad(),
          cell->getWidth() * positionPixel.w,
          cell->getHeight() * positionPixel.h};
      cell->setPositionPixel(cellRect);
      currentX += cellRect.w + positionPixel.w * cell->getXMargin() * 2 +
                  positionPixel.w * this->getXPad() * 2;
      auto temp = this->trimRect(cellRect);
      if (temp.second) {
        monitor.drawRectangle(temp.first, {255, 0, 0});
        cell->render(monitor);
      }
    }
  }
}
