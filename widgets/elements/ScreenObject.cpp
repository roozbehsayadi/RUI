
#include "ScreenObject.h"

void ScreenObject::draw(const Rect &screenRect, RuiMonitor &monitor, const Rect &showableArea) {
  Rect temp = {screenRect.x + positionPixel.x, screenRect.y + positionPixel.y, positionPixel.w, positionPixel.h};
  auto realWidthAndHeight = monitor.drawImage(temp, showableArea, imageTexture, imagePath);
  if (fullWidth && positionPixel.w < 0)
    positionPixel.w = realWidthAndHeight.first;
  if (fullHeight && positionPixel.h < 0)
    positionPixel.h = realWidthAndHeight.second;
}

void ScreenObject::setPositionPixel(const Rect &positionPixel) {
  this->positionPixel = positionPixel;
  if (positionPixel.w < 0)
    fullWidth = true;
  else
    fullWidth = false;
  if (positionPixel.h < 0)
    fullHeight = true;
  else
    fullHeight = false;
}

void ScreenObject::changeImagePath(const std::string &imagePath) {
  SDL_DestroyTexture(imageTexture);
  if (fullWidth)
    positionPixel.w = -1;
  if (fullHeight)
    positionPixel.h = -1;
  imageTexture = nullptr;
}
