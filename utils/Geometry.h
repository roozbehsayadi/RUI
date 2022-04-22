#ifndef __GEOMETRY_H
#define __GEOMETRY_H

#include "utils/Rect.h"

class Geometry {
public:
  // Rect must be in pixels, not percent
  static bool isPointInsideRect(double, double, const Rect &);

  // Return intersection of rects + if they intersect at all
  static const std::pair<Rect, bool> trimRect(const Rect &, const Rect &);
};

#endif
