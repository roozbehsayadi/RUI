
#include "Geometry.h"

bool Geometry::isPointInsideRect(double mouseX, double mouseY,
                                 const Rect &rect) {
  return mouseX >= rect.x && mouseX <= rect.x + rect.w && mouseY >= rect.y &&
         mouseY <= rect.y + rect.h;
}
