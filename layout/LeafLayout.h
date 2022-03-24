#ifndef __LEAF_LAYOUT_H
#define __LEAF_LAYOUT_H

#include <memory>

#include "BaseLayout.h"
#include "widgets/BaseWidget.h"

class LeafLayout : public BaseLayout {
public:
  LeafLayout() : LeafLayout(0.0, 0.0) {}
  LeafLayout(double width, double height, double xPad = 0.0, double yPad = 0.0,
             double xMargin = 0.0, double yMargin = 0.0)
      : BaseLayout(width, height, xPad, yPad, xMargin, yMargin) {
    type = LAYOUT_LEAF;
  }

  virtual void render(RuiMonitor &, const Rect &) const override;

  void setWidget(BaseWidget &widget) { this->widget = &widget; }

  const BaseWidget &getWidget() const { return *widget; }

private:
  BaseWidget *widget;
};

#endif // __LEAF_LAYOUT_H
