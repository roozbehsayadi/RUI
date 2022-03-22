#ifndef __RECT_H
#define __RECT_H

#include <ostream>

struct Rect {
  double x, y, w, h;
};

std::ostream &operator<<(std::ostream &, const Rect &);

#endif // __RECT_H
