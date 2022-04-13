
#include "ButtonWidget.h"

#include "utils/Geometry.h"

void ButtonWidget::draw(RuiMonitor &monitor) {
  monitor.drawRectangle(positionPixel, color);
  monitor.drawText(positionPixel, color, caption);
}

void ButtonWidget::handleClick(int mouseX, int mouseY) {
  if (Geometry::isPointInsideRect(mouseX, mouseY, positionPixel))
    this->clicked = true;
}

bool ButtonWidget::isClicked() {
  auto temp = this->clicked;
  this->clicked = false;
  return temp;
}
