#ifndef __BASE_LAYOUT_H
#define __BASE_LAYOUT_H

#include <memory>
#include <vector>

#include "monitor/RuiMonitor.h"
#include "utils/Rect.h"
#include "widgets/BaseWidget.h"

enum LayoutType {
  LAYOUT_UNKNOWN,
  LAYOUT_ROW,
  LAYOUT_COLUMN,
  LAYOUT_LEAF,
};

class BaseLayout {
public:
  BaseLayout(const std::string &slug) : BaseLayout(slug, 0.0, 0.0) {}
  BaseLayout(const std::string &slug, double width, double height,
             double xPad = 0.0, double yPad = 0.0, double xMargin = 0.0,
             double yMargin = 0.0)
      : slug(slug), width(width), height(height), xPad(xPad), yPad(yPad),
        xMargin(xMargin), yMargin(yMargin) {}

  virtual void render(RuiMonitor &) const = 0;

  virtual std::pair<std::shared_ptr<BaseWidget>, bool>
  getWidget(const std::string &) const = 0;

  virtual void handleClick(int, int) = 0;

  virtual bool setLayoutHidden(const std::string &, bool);

  void setPositionPixel(const Rect &positionPixel) {
    this->positionPixel = positionPixel;
  }

  void setWidth(double width) { this->width = width; }
  void setHeight(double height) { this->height = height; }
  void setXPad(double xPad) { this->xPad = xPad; }
  void setYPad(double yPad) { this->yPad = yPad; }
  void setXMargin(double xMargin) { this->xMargin = xMargin; }
  void setYMargin(double yMargin) { this->yMargin = yMargin; }

  void hide() { this->hidden = true; }
  void show() { this->hidden = false; }

  const std::string &getSlug() const { return this->slug; }

  double getWidth() const { return width; }
  double getHeight() const { return height; }
  double getXPad() const { return xPad; }
  double getYPad() const { return yPad; }
  double getXMargin() const { return xMargin; }
  double getYMargin() const { return yMargin; }

  bool isHidden() const { return this->hidden; }

protected:
  Rect getRectInPixels(const Rect &, int, int) const;
  Rect getChildRectPixels(const Rect &, std::shared_ptr<BaseLayout>) const;

  std::string slug;

  LayoutType type;
  double width, height;    // percentage inside the parent's layout (out of 1)
  double xPad, yPad;       // percentage of padding of inner elements (out of 1)
  double xMargin, yMargin; // percentage (out of 1)
  Rect positionPixel;
  bool hidden = false;
};

#endif // __BASE_LAYOUT_H
