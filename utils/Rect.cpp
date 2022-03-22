
#include "Rect.h"

std::ostream &operator<<(std::ostream &os, const Rect &rect) {
  os << rect.x << ',' << rect.y << ',' << rect.w << ',' << rect.h;
  return os;
}
