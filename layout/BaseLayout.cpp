
#include "BaseLayout.h"

#include "utils/Geometry.h"

const std::pair<Rect, bool> BaseLayout::trimRect(const Rect &rect) const {
  if (rect.x >= positionPixel.x + positionPixel.w ||
      positionPixel.x >= rect.x + rect.w)
    return {{}, false};
  if (rect.y + rect.h <= positionPixel.y ||
      positionPixel.y + positionPixel.h <= rect.y)
    return {{}, false};
  return {rect, true};
}

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
