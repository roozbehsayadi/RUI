
#include "ButtonWidget.h"

#include "utils/Geometry.h"

bool ButtonWidget::isClicked() {
  auto temp = !this->clicked;
  this->clicked = false;
  return temp;
}

void ButtonWidget::draw(RuiMonitor &monitor, const Color &color) {
  monitor.drawRectangle(positionPixel, color);
  monitor.drawText(positionPixel, color, caption);
}

void ButtonWidget::handleClick(int mouseX, int mouseY) {
  if (Geometry::isPointInsideRect(mouseX, mouseY, positionPixel))
    std::cout << positionPixel << std::endl;
}
