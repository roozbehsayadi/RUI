#ifndef __TEXTINPUT_WIDGET_H
#define __TEXTINPUT_WIDGET_H

#include "widgets/BaseWidget.h"

#include "utils/Color.h"

class TextInputWidget : public BaseWidget {
public:
  TextInputWidget(const std::string &slug) : BaseWidget(slug) {
    type = WIDGET_TEXT_INPUT;
    textColor = {255, 255, 255};
    boxColor = {75, 75, 255};
  }

  const std::string &getText() const;

  void setEnabled(bool);

protected:
  virtual void draw(RuiMonitor &, const Rect &) override;
  virtual void handleClick(int, int) override;
  virtual void handleTextInput(char) override;

  std::string text;

  Color textColor, boxColor;
};

#endif
