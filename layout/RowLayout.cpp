
#include "RowLayout.h"

#include <algorithm>

bool RowLayout::handleScroll(int scrollAmount, int mouseX, int mouseY) {
  bool somethingAffected = this->Container::handleScroll(scrollAmount, mouseX, mouseY);
  if (!somethingAffected && children.size() != 0 && Geometry::isPointInsideRect(mouseX, mouseY, positionPixel)) {
    if (scrollable) {
      if (scrollAmount < 0 && availableScrollSpaceLeft != 0)
        initialDistance += scrollAmount * std::min(availableScrollSpaceLeft, Container::SCROLL_SPEED);
      else if (scrollAmount > 0 && availableScrollSpaceRight != 0)
        initialDistance += scrollAmount * std::min(availableScrollSpaceRight, Container::SCROLL_SPEED);
      somethingAffected = true;
    }
  }
  return somethingAffected;
}

// TODO refactor this!!!
void RowLayout::render(RuiMonitor &monitor, const Rect &showableArea) {
  if (!this->hidden) {
    double currentX = this->initialDistance;
    for (auto i = 0u; i < children.size(); i++) {
      auto cell = children.at(i);
      if (cell->isHidden())
        continue;
      const Rect cellRect = {positionPixel.x + currentX + positionPixel.w * cell->getXMargin() +
                                 positionPixel.w * this->getXPad(),
                             positionPixel.y + positionPixel.h * cell->getYMargin() + positionPixel.h * this->getYPad(),
                             cell->getWidth() * positionPixel.w, cell->getHeight() * positionPixel.h};
      cell->setPositionPixel(cellRect);
      currentX += cellRect.w + positionPixel.w * cell->getXMargin() * 2 + positionPixel.w * this->getXPad() * 2;
      auto temp = Geometry::trimRect(showableArea, cellRect);
      if (temp.second) {
        if (children.at(i)->type != LAYOUT_LEAF)
          monitor.drawRectangle(temp.first, {255, 0, 0});
        cell->render(monitor, temp.first);
      }
    }
    setScrollableAndScrollSpace(positionPixel.w, availableScrollSpaceLeft, availableScrollSpaceRight);
  }
}

double RowLayout::totalChildrenLength(std::vector<std::shared_ptr<BaseLayout>> &children) const {
  if (children.size() != 0) {
    auto lastChild = children.at(children.size() - 1);
    auto lastChildPosition = lastChild->positionPixel;
    lastChildPosition.x += lastChild->getXMargin() * positionPixel.w;
    return lastChildPosition.x + lastChildPosition.w - initialDistance - positionPixel.x;
  } else
    return 0.0;
}

double RowLayout::getLayoutEnd(std::shared_ptr<BaseLayout> &l, int parentLength) const {
  return l->positionPixel.x + l->positionPixel.w + positionPixel.w * l->xMargin;
}

double RowLayout::getLayoutEnd(int parentLength) const {
  return positionPixel.x + positionPixel.w + parentLength * xMargin;
}
