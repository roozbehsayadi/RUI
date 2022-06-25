
#include "ColumnLayout.h"

#include <algorithm>

bool ColumnLayout::handleScroll(int scrollAmount, int mouseX, int mouseY) {
  bool somethingAffected = this->Container::handleScroll(scrollAmount, mouseX, mouseY);
  if (!somethingAffected && children.size() != 0 && Geometry::isPointInsideRect(mouseX, mouseY, positionPixel)) {
    if (scrollable) {
      if (scrollAmount < 0 && availableScrollSpaceUp != 0)
        initialDistance += scrollAmount * std::min(availableScrollSpaceUp, Container::SCROLL_SPEED);
      else if (scrollAmount > 0 && availableScrollSpaceDown != 0)
        initialDistance += scrollAmount * std::min(availableScrollSpaceDown, Container::SCROLL_SPEED);
      somethingAffected = true;
    }
  }

  if (somethingAffected)
    RuiSettings::mustRender = true;

  return somethingAffected;
}

// TODO refactor this!!!
void ColumnLayout::render(RuiMonitor &monitor, const Rect &showableArea) {
  if (!this->hidden) {
    double currentY = this->initialDistance;
    for (auto i = 0u; i < children.size(); i++) {
      auto cell = children.at(i);
      if (cell->isHidden())
        continue;
      const Rect cellRect = {positionPixel.x + positionPixel.w * cell->getXMargin() + positionPixel.w * this->getXPad(),
                             positionPixel.y + currentY + positionPixel.h * cell->getYMargin() +
                                 positionPixel.h * this->getYPad(),
                             cell->getWidth() * positionPixel.w, cell->getHeight() * positionPixel.h};
      cell->setPositionPixel(cellRect);
      currentY += cellRect.h + positionPixel.h * cell->getYMargin() * 2 + positionPixel.h * this->getYPad() * 2;
      auto temp = Geometry::trimRect(showableArea, cellRect);
      if (temp.second) {
        if (children.at(i)->type != LAYOUT_LEAF)
          monitor.drawRectangle(temp.first, {255, 0, 0});
        cell->render(monitor, temp.first);
      }
    }
    this->setScrollableAndScrollSpace(positionPixel.h, availableScrollSpaceUp, availableScrollSpaceDown);
  }
}

double ColumnLayout::totalChildrenLength(std::vector<std::shared_ptr<BaseLayout>> &children) const {
  if (children.size() != 0) {
    auto lastChild = children.at(children.size() - 1);
    auto lastChildPosition = lastChild->positionPixel;
    lastChildPosition.y += lastChild->getYMargin() * positionPixel.h;
    return lastChildPosition.y + lastChildPosition.h - initialDistance - positionPixel.y;
  } else
    return 0.0;
}

double ColumnLayout::getLayoutEnd(std::shared_ptr<BaseLayout> &l, int parentLength) const {
  return l->positionPixel.y + l->positionPixel.h + l->yMargin * parentLength;
}

double ColumnLayout::getLayoutEnd(int parentLength) const {
  return positionPixel.y + positionPixel.h + parentLength * yMargin;
}
