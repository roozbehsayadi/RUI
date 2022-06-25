
#include "BaseLayout.h"

#include "utils/Geometry.h"

const double BaseLayout::SCROLLABLE_EPSILON = 0.05;

void BaseLayout::setHidden(bool hidden) {
  this->hidden = hidden;
  RuiSettings::mustRender = true;
}

Rect BaseLayout::getRectInPixels(const Rect &rect, int xPadParent, int yPadParent) const {
  Rect returnValue{rect.x + xPadParent * rect.w + xMargin * rect.w, rect.y + yPadParent * rect.h + yMargin * rect.h,
                   width * rect.w, height * rect.h};
  return returnValue;
}

Rect BaseLayout::getChildRectPixels(const Rect &rect, std::shared_ptr<BaseLayout> child) const {
  return {rect.x + rect.w * xPad + rect.w * child->getXMargin(), rect.y + rect.h * yPad + rect.h * child->getYMargin(),
          rect.w * child->getWidth(), rect.h * child->getHeight()};
}
