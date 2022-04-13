
#include "LeafLayout.h"

void LeafLayout::render(RuiMonitor &monitor) const {
  if (!this->hidden) {
    monitor.drawRectangle(positionPixel, {255, 0, 0});
    // TODO handle if the widget was null?
    widget->setPositionPixel({positionPixel.x + xPad * positionPixel.w,
                              positionPixel.y + yPad * positionPixel.h,
                              positionPixel.w - 2 * xPad * positionPixel.w,
                              positionPixel.h - 2 * yPad * positionPixel.h});
    widget->draw(monitor);
  }
}

void LeafLayout::handleClick(int mouseX, int mouseY) {
  widget->handleClick(mouseX, mouseY);
}

bool LeafLayout::isClicked(const std::string &slug) {
  if (!widget->isEnabled())
    return false;
  if (widget->getType() == WIDGET_BUTTON && widget->getSlug() == slug) {
    auto button = std::dynamic_pointer_cast<ButtonWidget>(widget);
    return button->isClicked();
  }
  return false;
}

bool LeafLayout::setEnabledWidget(const std::string &slug, bool enabled) {
  if (widget->getType() == WIDGET_BUTTON && widget->getSlug() == slug) {
    auto button = std::dynamic_pointer_cast<ButtonWidget>(widget);
    button->setEnabled(enabled);
    return true;
  }
  return false;
}
