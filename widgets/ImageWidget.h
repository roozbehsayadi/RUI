#ifndef __IMAGE_WIDGET_H
#define __IMAGE_WIDGET_H

#include "SDL2/SDL.h"

#include "BaseWidget.h"

class ImageWidget : public BaseWidget {
public:
  ImageWidget(const std::string &slug, const std::string &imagePath)
      : BaseWidget(slug), imagePath(imagePath) {
    this->type = WIDGET_IMAGE;
  }

  virtual void draw(RuiMonitor &monitor) override;
  virtual void handleClick(int, int) override{};

  void changeImagePath(const std::string &imagePath);

private:
  SDL_Texture *imageTexture = nullptr;
  std::string imagePath;
};

#endif // __IMAGE_WIDGET_H
