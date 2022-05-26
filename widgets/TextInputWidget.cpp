
#include "TextInputWidget.h"

void TextInputWidget::draw(RuiMonitor &monitor, const Rect &showableArea) {
  if (focused) {
    Color tempColor = color;
    tempColor.setAlpha(200);
    monitor.drawRectangle(showableArea, tempColor);
  } else
    monitor.drawRectangle(showableArea, color);
  monitor.drawText(positionPixel, showableArea, color, text, FONT_FIT_VERTICAL);
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
