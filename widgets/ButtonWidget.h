#ifndef __BUTTON_WIDGET_H
#define __BUTTON_WIDGET_H

#include <iostream>
#include <string>

#include "BaseWidget.h"
#include "monitor/RuiMonitor.h"
#include "utils/Rect.h"

class ButtonWidget : public BaseWidget {
public:
  ButtonWidget(const std::string &slug, const std::string &caption)
      : BaseWidget(slug), caption(caption) {
    type = WIDGET_BUTTON;
  }

  virtual void draw(RuiMonitor &monitor, const Color &color) override;
  virtual void handleClick(int, int) override;

  // Returns whether the button was clicked or not
  // and sets the "clicked" variable to false.
  virtual bool isClicked() final;

  void setCaption(const std::string &caption) { this->caption = caption; }

  const std::string &getCaption() const { return this->caption; }

private:
  std::string caption;

  bool clicked = false;
};

#endif
