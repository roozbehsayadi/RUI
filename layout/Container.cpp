
#include "Container.h"

#include "utils/Geometry.h"

void Container::handleClick(int mouseX, int mouseY) {
  if (hidden)
    return;
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

bool Container::setLayoutHidden(const std::string &slug, bool hidden) {
  if (this->BaseLayout::setLayoutHidden(slug, hidden)) {
    return true;
  }
  for (auto &child : children) {
    if (child->setLayoutHidden(slug, hidden))
      return true;
  }
  return false;
}

bool Container::setEnabledWidget(const std::string &slug, bool enabled) {
  for (auto &child : children) {
    if (child->setEnabledWidget(slug, enabled))
      return true;
  }
  return false;
}

void Container::render(RuiMonitor &monitor) const {
  if (!this->hidden) {
    monitor.drawRectangle(positionPixel, {255, 0, 0});
    for (auto child : children) {
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
