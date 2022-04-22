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

class LeafLayout;

class BaseWidget {

  friend class LeafLayout;

public:
  BaseWidget(const std::string &slug) : slug(slug) { type = WIDGET_UNKNOWN; }

  void setPositionPixel(const Rect &positionPixel) {
    this->positionPixel = positionPixel;
  }

  virtual const WidgetType &getType() const { return this->type; }
  const std::string &getSlug() const { return this->slug; }

  // Returns whether the button was clicked or not
  // and sets the "clicked" variable to false.
  virtual bool isClicked() final;

  bool isEnabled() const { return this->enabled; }
  void setEnabled(bool enabled) { this->enabled = enabled; }

protected:
  virtual void draw(RuiMonitor &, const Rect &) = 0;
  virtual void handleClick(int, int) = 0;

  WidgetType type;
  std::string slug;

  bool clicked = false;

  bool enabled = true;

  Rect positionPixel;
};

#endif // __BASE_WIDGET_H
