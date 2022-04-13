
#include "Container.h"

#include "utils/Geometry.h"

void Container::handleClick(int mouseX, int mouseY) {
  if (Geometry::isPointInsideRect(mouseX, mouseY, positionPixel))
    for (auto &child : children) {
      child->handleClick(mouseX, mouseY);
    }
}

bool Container::isClicked(const std::string &slug) {
  for (auto &child : children) {
    if (child->isClicked(slug))
      return true;
  }
  return false;
}

void Container::render(RuiMonitor &monitor) const {
  monitor.drawRectangle(positionPixel, {255, 0, 0});
  for (auto child : children) {
    if (!child->isHidden()) {
      Rect temp{positionPixel.x + positionPixel.w * xPad +
                    positionPixel.w * child->getXMargin(),
                positionPixel.y + positionPixel.h * yPad +
                    positionPixel.h * child->getYMargin(),
                positionPixel.w * child->getWidth(),
                positionPixel.h * child->getHeight()};
      child->setPositionPixel(temp);
      child->render(monitor);
    }
  }
}
