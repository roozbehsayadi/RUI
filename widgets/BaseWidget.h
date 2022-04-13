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
  WIDGET_IMAGE,
};

class BaseWidget {
public:
  BaseWidget(const std::string &slug) : slug(slug) { type = WIDGET_UNKNOWN; }

  virtual void draw(RuiMonitor &) = 0;
  virtual void handleClick(int, int) = 0;

  void setPositionPixel(const Rect &positionPixel) {
    this->positionPixel = positionPixel;
  }

  virtual const WidgetType &getType() const { return this->type; }
  const std::string &getSlug() const { return this->slug; }

  bool isEnabled() const { return this->enabled; }
  void setEnabled(bool enabled) { this->enabled = enabled; }

protected:
  WidgetType type;
  std::string slug;

  bool enabled = true;

  Rect positionPixel;
};

#endif // __BASE_WIDGET_H
