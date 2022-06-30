
#include "ButtonWidget.h"

#include "utils/Geometry.h"

void ButtonWidget::draw(RuiMonitor &monitor, const Rect &showableArea) {
  monitor.drawRectangle(showableArea, color);
  monitor.drawText(positionPixel, showableArea, color, caption);
}

void ButtonWidget::handleClick(int mouseX, int mouseY) {
  if (!this->enabled)
    return;
  if (Geometry::isPointInsideRect(mouseX, mouseY, positionPixel))
    this->clicked = true;
}
