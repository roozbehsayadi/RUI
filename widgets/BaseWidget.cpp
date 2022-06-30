
#include "BaseWidget.h"

bool BaseWidget::isClicked() {
  auto temp = this->clicked;
  this->clicked = false;
  return temp;
}
