#ifndef __LEAF_LAYOUT_H
#define __LEAF_LAYOUT_H

#include <algorithm>
#include <memory>

#include "BaseLayout.h"

#include "RuiSettings.h"
#include "widgets/BaseWidget.h"
#include "widgets/ButtonWidget.h"
#include "widgets/ScreenWidget.h"

class LeafLayout : public BaseLayout {
public:
  LeafLayout(const std::string &slug) : LeafLayout(slug, 0.0, 0.0) {}
  LeafLayout(const std::string &slug, double width, double height, double xPad = 0.0, double yPad = 0.0,
             double xMargin = 0.0, double yMargin = 0.0)
      : BaseLayout(slug, width, height, xPad, yPad, xMargin, yMargin) {
    type = LAYOUT_LEAF;
  }

  virtual void render(RuiMonitor &, const Rect &) override;

  virtual std::pair<std::shared_ptr<BaseWidget>, bool> getWidget(const std::string &) const override;

  virtual std::shared_ptr<BaseLayout> getLayout(const std::string &) const {
    // has no children
    return nullptr;
  }

  virtual void handleClick(int, int) override;
  virtual bool handleScroll(int, int, int) override { return false; }

  virtual bool handleTextInput(char) override;

  virtual bool handleDrag(int, int) override;
  virtual bool handleDrop() override;

  virtual bool hasFocusedWidget() const override;

  void setWidget(std::shared_ptr<BaseWidget> widget) { this->widget = widget; }

  const BaseWidget &getWidget() const { return *widget; }

protected:
  // These two below function imply bad design!
  virtual double getLayoutEnd(std::shared_ptr<BaseLayout> &, int = 0) const override { return 0.0; }
  virtual double getLayoutEnd(int = 0) const override { return 0.0; }

  virtual void removeFocus() override;

private:
  std::shared_ptr<BaseWidget> widget;
};

#endif // __LEAF_LAYOUT_H
