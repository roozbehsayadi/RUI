#ifndef __CONTAINER_H
#define __CONTAINER_H

#include <iostream>
#include <memory>

#include "BaseLayout.h"
#include "monitor/RuiMonitor.h"

class Container : public BaseLayout {
public:
  Container() : Container(0.0, 0.0, 0.0, 0.0) {}
  Container(double width, double height, double xPad = 0.0, double yPad = 0.0,
            double xMargin = 0.0, double yMargin = 0.0)
      : BaseLayout(width, height, xPad, yPad, xMargin, yMargin) {
    type = LAYOUT_UNKNOWN;
  }

  virtual void handleClick(int, int) override;
  virtual bool isClicked(const std::string &) override;

  void addChild(std::shared_ptr<BaseLayout> child) {
    children.push_back(child);
  }

  virtual void render(RuiMonitor &) const override;

protected:
  std::vector<std::shared_ptr<BaseLayout>> children;
};

#endif // __CONTAINER_H