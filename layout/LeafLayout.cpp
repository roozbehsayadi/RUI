
#include "LeafLayout.h"

void LeafLayout::render(RuiMonitor &monitor, const Rect &showableArea) {
  if (!this->hidden) {
    // TODO handle if the widget was null?
    widget->setPositionPixel({positionPixel.x + xPad * positionPixel.w, positionPixel.y + yPad * positionPixel.h,
                              positionPixel.w - 2 * xPad * positionPixel.w,
                              positionPixel.h - 2 * yPad * positionPixel.h});
    widget->draw(monitor, showableArea);
  }
}

std::pair<std::shared_ptr<BaseWidget>, bool> LeafLayout::getWidget(const std::string &slug) const {
  if (this->widget->getSlug() == slug)
    return std::make_pair(this->widget, this->hidden);
  return std::make_pair(nullptr, false);
}

void LeafLayout::handleClick(int mouseX, int mouseY) {
  if (hidden)
    return;
  widget->handleClick(mouseX, mouseY);
}

bool LeafLayout::handleTextInput(char key) {
  if (widget->getType() == WIDGET_TEXT_INPUT && widget->isFocused()) {
    widget->handleTextInput(key);
    return true;
  }
  return false;
}

bool LeafLayout::handleDrag(int mouseX, int mouseY) {
  if (hidden)
    return false;

  if (Geometry::isPointInsideRect(mouseX, mouseY, positionPixel)) {
    if (widget->getType() == WIDGET_SCREEN) {
      auto temp = std::dynamic_pointer_cast<ScreenWidget>(widget);
      temp->handleDrag(mouseX, mouseY);
      return true;
    }
  }
  return false;
}

bool LeafLayout::handleDrop() {
  if (hidden)
    return false;

  if (widget->getType() == WIDGET_SCREEN) {
    auto temp = std::dynamic_pointer_cast<ScreenWidget>(widget);
    temp->handleDrop();
    return true;
  }
  return false;
}

bool LeafLayout::hasFocusedWidget() const { return widget->isFocused(); }

void LeafLayout::removeFocus() { widget->focused = false; }
