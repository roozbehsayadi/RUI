#ifndef __LEAF_LAYOUT_H
#define __LEAF_LAYOUT_H

#include <memory>

#include "BaseLayout.h"

#include "widgets/BaseWidget.h"
#include "widgets/ButtonWidget.h"

class LeafLayout : public BaseLayout {
public:
  LeafLayout(const std::string &slug) : LeafLayout(slug, 0.0, 0.0) {}
  LeafLayout(const std::string &slug, double width, double height,
             double xPad = 0.0, double yPad = 0.0, double xMargin = 0.0,
             double yMargin = 0.0)
      : BaseLayout(slug, width, height, xPad, yPad, xMargin, yMargin) {
    type = LAYOUT_LEAF;
  }

  virtual void render(RuiMonitor &) const override;

  virtual void handleClick(int, int) override;
  virtual bool isClicked(const std::string &) override;

  virtual bool setEnabledWidget(const std::string &, bool) override;

  void setWidget(std::shared_ptr<BaseWidget> widget) { this->widget = widget; }

  const BaseWidget &getWidget() const { return *widget; }

private:
  std::shared_ptr<BaseWidget> widget;
};

#endif // __LEAF_LAYOUT_H
