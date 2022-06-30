
#include "ScreenObject.h"

void ScreenObject::draw(const Rect &screenRect, RuiMonitor &monitor, const Rect &showableArea) {
  Rect temp = {screenRect.x + positionPixel.x, screenRect.y + positionPixel.y, positionPixel.w, positionPixel.h};
  monitor.drawImage(temp, showableArea, imageTexture, imagePath);
}

void ScreenObject::changeImagePath(const std::string &imagePath) {
  SDL_DestroyTexture(imageTexture);
  imageTexture = nullptr;
}
