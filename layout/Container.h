#ifndef __CONTAINER_H
#define __CONTAINER_H

#include <iostream>
#include <memory>

#include "BaseLayout.h"
#include "monitor/RuiMonitor.h"

class Container : public BaseLayout {
public:
  Container(const std::string &slug) : Container(slug, 0.0, 0.0, 0.0, 0.0) {}
  Container(const std::string &slug, double width, double height,
            double xPad = 0.0, double yPad = 0.0, double xMargin = 0.0,
            double yMargin = 0.0)
      : BaseLayout(slug, width, height, xPad, yPad, xMargin, yMargin) {
    type = LAYOUT_UNKNOWN;
  }

  virtual std::pair<std::shared_ptr<BaseWidget>, bool>
  getWidget(const std::string &) const override;

  virtual std::shared_ptr<BaseLayout>
  getLayout(const std::string &) const override;

  virtual void handleClick(int, int) override;

  virtual bool setLayoutHidden(const std::string &, bool) override;

  void addChild(std::shared_ptr<BaseLayout> child) {
    children.push_back(child);
  }

  virtual void render(RuiMonitor &) const override;

protected:
  std::vector<std::shared_ptr<BaseLayout>> children;
};

#endif // __CONTAINER_H