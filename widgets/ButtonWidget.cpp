
#include "ButtonWidget.h"

#include "utils/Geometry.h"

void ButtonWidget::draw(RuiMonitor &monitor, const Color &color) {
  monitor.drawRectangle(positionPixel, color);
  monitor.drawText(positionPixel, color, caption);
}

void ButtonWidget::handleClick(int mouseX, int mouseY) {
  if (Geometry::isPointInsideRect(mouseX, mouseY, positionPixel))
    this->clicked = true;
    // std::cout << positionPixel << std::endl;
}
