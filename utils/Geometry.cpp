
#include "Geometry.h"

bool Geometry::isPointInsideRect(double mouseX, double mouseY,
                                 const Rect &rect) {
  return mouseX >= rect.x && mouseX <= rect.x + rect.w && mouseY >= rect.y &&
         mouseY <= rect.y + rect.h;
}

const std::pair<Rect, bool> Geometry::trimRect(const Rect &rect1,
                                               const Rect &rect2) {
  if (rect2.x >= rect1.x + rect1.w || rect1.x >= rect2.x + rect2.w)
    return {{}, false};
  if (rect2.y + rect2.h <= rect1.y || rect1.y + rect1.h <= rect2.y)
    return {{}, false};
  Rect intersection;
  intersection.x = std::max(rect1.x, rect2.x);
  intersection.y = std::max(rect1.y, rect2.y);
  intersection.w = std::min(rect1.x + rect1.w, rect2.x + rect2.w) -
                   std::max(rect1.x, rect2.x);
  intersection.h = std::min(rect1.y + rect1.h, rect2.y + rect2.h) -
                   std::max(rect1.y, rect2.y);
  return {intersection, true};
}
