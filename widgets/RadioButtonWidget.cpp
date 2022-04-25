
#include "RadioButtonWidget.h"

template <typename T>
const std::string RadioButtonWidget<T>::SELECTED_ASSET_PATH =
    "assets/rui_images/selected_radio_button.png";
template <typename T>
const std::string RadioButtonWidget<T>::UNSELECTED_ASSET_PATH =
    "assets/rui_images/unselected_radio_button.png";

template <typename T>
void RadioButtonWidget<T>::draw(RuiMonitor &monitor, const Rect &showableArea) {
  auto radioButtonLength =
      std::min({positionPixel.h, positionPixel.w / 10.0, 50.0});
  Rect boxRect{positionPixel.x + 5,
               positionPixel.y + (positionPixel.h - radioButtonLength) / 2,
               radioButtonLength, radioButtonLength};
  auto temp = Geometry::trimRect(boxRect, showableArea);
  if (!temp.second)
    return;
  monitor.drawBox(temp.first, {255, 255, 255});
  if (variable == valueToAssign)
    monitor.drawImage(boxRect, showableArea, checkedTexture,
                      RadioButtonWidget::SELECTED_ASSET_PATH);
  else
    monitor.drawImage(boxRect, showableArea, uncheckedTexture,
                      RadioButtonWidget::UNSELECTED_ASSET_PATH);
  monitor.drawText({boxRect.x + boxRect.w + 5, boxRect.y,
                    positionPixel.w - boxRect.w - 5, radioButtonLength},
                   showableArea, {255, 255, 255}, label);
}

template <typename T>
void RadioButtonWidget<T>::handleClick(int mouseX, int mouseY) {
  if (!this->enabled)
    return;
  if (Geometry::isPointInsideRect(mouseX, mouseY, positionPixel))
    variable = valueToAssign;
}
