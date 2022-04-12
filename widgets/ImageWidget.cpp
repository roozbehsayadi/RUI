
#include "ImageWidget.h"

void ImageWidget::draw(RuiMonitor &monitor, const Color &color) {
  monitor.drawImage(positionPixel, imageTexture, imagePath);
}

void ImageWidget::changeImagePath(const std::string &imagePath) {
  SDL_DestroyTexture(imageTexture);
  imageTexture = nullptr;
}
