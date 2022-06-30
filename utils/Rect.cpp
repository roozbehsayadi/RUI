
#include "Rect.h"

std::ostream &operator<<(std::ostream &os, const Rect &rect) {
  os << rect.x << ',' << rect.y << ',' << rect.w << ',' << rect.h;
  return os;
}

Rect::operator SDL_Rect() const { return SDL_Rect{int(x), int(y), int(w), int(h)}; }

Rect::operator SDL_FRect() const { return SDL_FRect{float(x), float(y), float(w), float(h)}; }
