
#include "ImageWidget.h"

void ImageWidget::draw(RuiMonitor &monitor, const Rect &showableArea) {
  monitor.drawImage(positionPixel, showableArea, imageTexture, imagePath);
}

void ImageWidget::changeImagePath(const std::string &imagePath) {
  SDL_DestroyTexture(imageTexture);
  imageTexture = nullptr;
}
