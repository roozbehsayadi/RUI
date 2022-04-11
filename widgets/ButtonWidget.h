#ifndef __BUTTON_WIDGET_H
#define __BUTTON_WIDGET_H

#include <iostream>
#include <string>

#include "BaseWidget.h"
#include "monitor/RuiMonitor.h"
#include "utils/Rect.h"

class ButtonWidget : public BaseWidget {
public:
  // Caption cannot be empty, otherwise the program crashes
  ButtonWidget(const std::string &slug, const std::string &caption = "")
      : slug(slug), caption(caption) {}

  virtual void draw(RuiMonitor &monitor, const Color &color) override;
  virtual void handleClick(int, int) override;

  // Returns whether the button was clicked or not
  // and sets the "clicked" variable to false.
  bool isClicked();

  void setCaption(const std::string &caption) { this->caption = caption; }

  const std::string &getSlug() const { return this->slug; }
  const std::string &getCaption() const { return this->caption; }

private:
  std::string caption;
  std::string slug;
  bool clicked = false;
};

#endif
