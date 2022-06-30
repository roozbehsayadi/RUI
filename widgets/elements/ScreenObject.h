#ifndef __SCREEN_OBJECT_H
#define __SCREEN_OBJECT_H

#include "SDL2/SDL.h"

#include "monitor/RuiMonitor.h"
#include "utils/Rect.h"

class ScreenObject {
public:
  ScreenObject(const std::string &slug, const std::string &imagePath, const Rect &positionPixel)
      : slug(slug), imagePath(imagePath) {
    setPositionPixel(positionPixel);
  }

  virtual void draw(const Rect &, RuiMonitor &, const Rect &);

  void setPositionPixel(const Rect &positionPixel);
  void changeImagePath(const std::string &);

  const Rect &getPositionPixel() const { return this->positionPixel; }
  const std::string &getSlug() const { return this->slug; }

protected:
  std::string slug;
  int level;

  // absolute positionPixel
  Rect positionPixel;

  std::string imagePath;

  bool fullWidth = false, fullHeight = false;
  SDL_Texture *imageTexture = nullptr;
};

#endif // __SCREEN_OBJECT_H
