#ifndef __BASE_LAYOUT_H
#define __BASE_LAYOUT_H

#include <memory>
#include <vector>

#include "monitor/RuiMonitor.h"
#include "utils/Rect.h"

enum LayoutType {
  LAYOUT_UNKNOWN,
  LAYOUT_ROW,
  LAYOUT_COLUMN,
  LAYOUT_LEAF,
};

class BaseLayout {
public:
  BaseLayout() : BaseLayout(0.0, 0.0) {}
  BaseLayout(double width, double height, double xPad = 0.0, double yPad = 0.0,
             double xMargin = 0.0, double yMargin = 0.0)
      : width(width), height(height), xPad(xPad), yPad(yPad), xMargin(xMargin),
        yMargin(yMargin) {
    type = LAYOUT_UNKNOWN;
  }

  virtual void render(RuiMonitor &, const Rect &) const;

  void addChild(BaseLayout *child) { grid.push_back(child); }

  void setWidth(double width) { this->width = width; }
  void setHeight(double height) { this->height = height; }
  void setXPad(double xPad) { this->xPad = xPad; }
  void setYPad(double yPad) { this->yPad = yPad; }
  void setXMargin(double xMargin) { this->xMargin = xMargin; }
  void setYMargin(double yMargin) { this->yMargin = yMargin; }

  double getWidth() const { return width; }
  double getHeight() const { return height; }
  double getXPad() const { return xPad; }
  double getYPad() const { return yPad; }
  double getXMargin() const { return xMargin; }
  double getYMargin() const { return yMargin; }

protected:
  LayoutType type;
  double width, height;    // percentage inside the parent's layout (out of 1)
  double xPad, yPad;       // percentage of padding of inner elements (out of 1)
  double xMargin, yMargin; // percentage (out of 1)
  std::vector<BaseLayout *> grid;
};

#endif // __BASE_LAYOUT_H
