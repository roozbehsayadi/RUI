
#include "ButtonWidget.h"

#include "utils/Geometry.h"

void ButtonWidget::draw(RuiMonitor &monitor) {
  monitor.drawRectangle(positionPixel, color);
  monitor.drawText(positionPixel, color, caption);
}

void ButtonWidget::handleClick(int mouseX, int mouseY) {
  if (!this->enabled)
    return;
  if (Geometry::isPointInsideRect(mouseX, mouseY, positionPixel))
    this->clicked = true;
}
