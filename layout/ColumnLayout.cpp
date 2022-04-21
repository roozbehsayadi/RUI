
#include "ColumnLayout.h"

bool ColumnLayout::handleScroll(int scrollAmount, int mouseX, int mouseY) {
  bool somethingAffected =
      this->Container::handleScroll(scrollAmount, mouseX, mouseY);
  if (!somethingAffected && children.size() != 0 &&
      Geometry::isPointInsideRect(mouseX, mouseY, positionPixel)) {
    if (this->scrollable) {
      this->initialDistance += scrollAmount * Container::SCROLL_SPEED;
      somethingAffected = true;
    }
  }
  return somethingAffected;
}

// TODO refactor this!!!
void ColumnLayout::render(RuiMonitor &monitor) {
  if (!this->hidden) {
    monitor.drawRectangle(positionPixel, {255, 0, 0});
    double currentY = this->initialDistance;
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
      // TODO chera in akharesh *2 nadare vali oon yeki dare?
      currentY += cellRect.h + positionPixel.h * cell->getYMargin() * 2 +
                  positionPixel.h * this->getYPad() * 2;
      auto temp = this->trimRect(cellRect);
      if (temp.second) {
        monitor.drawRectangle(temp.first, {255, 0, 0});
        cell->render(monitor);
      }
    }
    if (children.size() != 0) {
      auto lastChildPosition = children.at(children.size() - 1)->positionPixel;
      double childrenTotalHeight = lastChildPosition.y + lastChildPosition.h -
                                   initialDistance - positionPixel.y;
      scrollable = childrenTotalHeight > positionPixel.h;
    }
  }
}
