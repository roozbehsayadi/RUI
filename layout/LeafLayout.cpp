
#include "LeafLayout.h"

void LeafLayout::render(RuiMonitor &monitor) const {
  monitor.drawRectangle(positionPixel, {255, 0, 0});
  widget->setPositionPixel({positionPixel.x + xPad * positionPixel.w,
                            positionPixel.y + yPad * positionPixel.h,
                            positionPixel.w - 2 * xPad * positionPixel.w,
                            positionPixel.h - 2 * yPad * positionPixel.h});
  widget->draw(monitor, {0, 255, 0});
}

void LeafLayout::handleClick(int mouseX, int mouseY) {
  this->BaseLayout::handleClick(mouseX, mouseY);
  widget->handleClick(mouseX, mouseY);
}
