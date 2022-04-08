#ifndef __BUTTON_WIDGET_H
#define __BUTTON_WIDGET_H

#include <iostream>
#include <string>

#include "BaseWidget.h"
#include "monitor/RuiMonitor.h"
#include "utils/Rect.h"

class ButtonWidget : public BaseWidget {
public:
  ButtonWidget() : ButtonWidget("") {}
  ButtonWidget(std::string caption) : caption(caption) {}

  virtual void draw(RuiMonitor &monitor, const Color &color) override;
  virtual void handleClick(int, int) override;

  void setCaption(const std::string &caption) { this->caption = caption; }

  const std::string &getCaption() const { return this->caption; }

private:
  std::string caption;
};

#endif
