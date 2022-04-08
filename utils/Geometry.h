#ifndef __GEOMETRY_H
#define __GEOMETRY_H

#include "utils/Rect.h"

class Geometry {
public:
  // Rect must be in pixels, not percent
  static bool isPointInsideRect(double, double, const Rect &);
};

#endif
