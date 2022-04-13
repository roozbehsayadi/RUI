
#include "ImageWidget.h"

void ImageWidget::draw(RuiMonitor &monitor) {
  monitor.drawImage(positionPixel, imageTexture, imagePath);
}

void ImageWidget::changeImagePath(const std::string &imagePath) {
  SDL_DestroyTexture(imageTexture);
  imageTexture = nullptr;
}
