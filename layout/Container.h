#ifndef __CONTAINER_H
#define __CONTAINER_H

#include <iostream>
#include <memory>

#include "BaseLayout.h"
#include "RuiSettings.h"
#include "monitor/RuiMonitor.h"

class Container : public BaseLayout {
public:
  Container(const std::string &slug) : Container(slug, 0.0, 0.0, 0.0, 0.0) {}
  Container(const std::string &slug, double width, double height, double xPad = 0.0, double yPad = 0.0,
            double xMargin = 0.0, double yMargin = 0.0)
      : BaseLayout(slug, width, height, xPad, yPad, xMargin, yMargin) {
    type = LAYOUT_UNKNOWN;
  }

  virtual std::pair<std::shared_ptr<BaseWidget>, bool> getWidget(const std::string &) const override;

  virtual std::shared_ptr<BaseLayout> getLayout(const std::string &) const override;

  virtual void handleClick(int, int) override;
  virtual bool handleScroll(int, int, int) override;

  virtual bool handleTextInput(char) override;

  virtual bool handleDrag(int, int) override;
  virtual bool handleDrop() override;

  virtual bool hasFocusedWidget() const override;

  void addChild(std::shared_ptr<BaseLayout> child) { children.push_back(child); }

  virtual void render(RuiMonitor &, const Rect &) override;

protected:
  std::vector<std::shared_ptr<BaseLayout>> children;

  std::vector<std::shared_ptr<BaseLayout>> getVisibleChildren();
  virtual double totalChildrenLength(std::vector<std::shared_ptr<BaseLayout>> &) const = 0;

  virtual double getLayoutEnd(std::shared_ptr<BaseLayout> &, int = 0) const = 0;
  virtual double getLayoutEnd(int = 0) const = 0;

  virtual void removeFocus() override;

  void setScrollableAndScrollSpace(int, int &, int &);

  bool scrollable = false;
  const static int SCROLL_SPEED;
};

#endif // __CONTAINER_H
