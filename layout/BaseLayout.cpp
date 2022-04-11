
#include "BaseLayout.h"

#include <iostream>

#include "utils/Geometry.h"

// void BaseLayout::handleClick(int mouseX, int mouseY) {
//   if (Geometry::isPointInsideRect(mouseX, mouseY, positionPixel))
//     std::cout << positionPixel << std::endl;
// }

Rect BaseLayout::getRectInPixels(const Rect &rect, int xPadParent,
                                 int yPadParent) const {
  Rect returnValue{rect.x + xPadParent * rect.w + xMargin * rect.w,
                   rect.y + yPadParent * rect.h + yMargin * rect.h,
                   width * rect.w, height * rect.h};
  return returnValue;
}

Rect BaseLayout::getChildRectPixels(const Rect &rect,
                                    std::shared_ptr<BaseLayout> child) const {
  return {rect.x + rect.w * xPad + rect.w * child->getXMargin(),
          rect.y + rect.h * yPad + rect.h * child->getYMargin(),
          rect.w * child->getWidth(), rect.h * child->getHeight()};
}