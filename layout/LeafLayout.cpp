
#include "LeafLayout.h"

void LeafLayout::render(RuiMonitor &monitor) {
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

std::pair<std::shared_ptr<BaseWidget>, bool>
LeafLayout::getWidget(const std::string &slug) const {
  if (this->widget->getSlug() == slug)
    return std::make_pair(this->widget, this->hidden);
  return std::make_pair(nullptr, false);
}

void LeafLayout::handleClick(int mouseX, int mouseY) {
  if (hidden)
    return;
  widget->handleClick(mouseX, mouseY);
}
