
#include "TextInputWidget.h"

void TextInputWidget::draw(RuiMonitor &monitor, const Rect &showableArea) {
  if (focused) {
    Color tempColor = boxColor;
    tempColor.setRed(tempColor.getRed() + 150);
    tempColor.setRed(tempColor.getGreen() + 150);
    monitor.drawRectangle(showableArea, tempColor);
  } else
    monitor.drawRectangle(showableArea, boxColor);
  monitor.drawText(positionPixel, showableArea, textColor, text, FONT_FIT_VERTICAL);
}

const std::string &TextInputWidget::getText() const { return this->text; }

void TextInputWidget::setEnabled(bool enabled) {
  BaseWidget::setEnabled(enabled);
  if (!enabled)
    focused = false;
}

void TextInputWidget::handleClick(int mouseX, int mouseY) {
  if (!this->enabled)
    return;
  if (Geometry::isPointInsideRect(mouseX, mouseY, positionPixel))
    focused = true;
  else
    focused = false;
}

void TextInputWidget::handleTextInput(char key) {
  if (key >= SDLK_SPACE && key <= SDLK_z)
    text += char(key);
  else if (key == SDLK_BACKSPACE)
    if (text.size() != 0)
      text.pop_back();
}
