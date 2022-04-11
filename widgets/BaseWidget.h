#ifndef __BASE_WIDGET_H
#define __BASE_WIDGET_H

#include <string>
#include <utility>
#include <vector>

#include "monitor/RuiMonitor.h"
#include "utils/Color.h"
#include "utils/Rect.h"

enum WidgetType {
  WIDGET_UNKNOWN,
  WIDGET_BUTTON,
};

class BaseWidget {
public:
  BaseWidget(const std::string &slug) : slug(slug) { type = WIDGET_UNKNOWN; }

  virtual void draw(RuiMonitor &, const Color &) = 0;
  virtual void handleClick(int, int) = 0;

  // Returns whether the button was clicked or not
  // and sets the "clicked" variable to false.
  virtual bool isClicked() final;

  void setPositionPixel(const Rect &positionPixel) {
    this->positionPixel = positionPixel;
  }

  const WidgetType &getType() const { return this->type; }
  const std::string &getSlug() const { return this->slug; }

protected:
  WidgetType type;
  std::string slug;
  bool clicked = false;

  Rect positionPixel;
};

#endif // __BASE_WIDGET_H
