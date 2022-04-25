
#include "CheckboxWidget.h"

const std::string CheckboxWidget::ASSET_PATH = "assets/rui_images/check.png";

void CheckboxWidget::draw(RuiMonitor &monitor, const Rect &showableArea) {
  auto checkboxLength = std::min({positionPixel.h, positionPixel.w / 10.0, 50.0});
  Rect boxRect{positionPixel.x + 5, positionPixel.y + (positionPixel.h - checkboxLength) / 2, checkboxLength,
               checkboxLength};
  auto temp = Geometry::trimRect(boxRect, showableArea);
  if (!temp.second)
    return;
  monitor.drawBox(temp.first, {255, 255, 255});
  if (variable) {
    monitor.drawImage(boxRect, showableArea, boxTexture, CheckboxWidget::ASSET_PATH);
  }
  monitor.drawText({boxRect.x + boxRect.w + 5, boxRect.y, positionPixel.w - boxRect.w - 5, checkboxLength},
                   showableArea, {255, 255, 255}, label);
}

void CheckboxWidget::handleClick(int mouseX, int mouseY) {
  if (!this->enabled)
    return;
  if (Geometry::isPointInsideRect(mouseX, mouseY, positionPixel))
    variable = !variable;
}
