#ifndef __RECT_H
#define __RECT_H

#include <ostream>

#include <SDL2/SDL.h>

struct Rect {
  double x, y, w, h;

  // Easy cast to SDL_Rect
  operator SDL_Rect() const;
};

std::ostream &operator<<(std::ostream &, const Rect &);

#endif // __RECT_H
