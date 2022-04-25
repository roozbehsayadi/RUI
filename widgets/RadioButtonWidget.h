#ifndef __RADIOBUTTON_WIDGET_H
#define __RADIOBUTTON_WIDGET_H

#include "widgets/BaseWidget.h"

#include <algorithm>

template <typename T> class RadioButtonWidget : public BaseWidget {
public:
  RadioButtonWidget(const std::string &slug, T &variable, const std::string &label, const T &valueToAssign)
      : BaseWidget(slug), variable(variable), label(label), valueToAssign(valueToAssign) {}

protected:
  virtual void draw(RuiMonitor &, const Rect &) override;
  virtual void handleClick(int, int) override;

  T &variable;
  std::string label;
  const T valueToAssign;

  SDL_Texture *checkedTexture = nullptr, *uncheckedTexture = nullptr;

private:
  const static std::string SELECTED_ASSET_PATH;
  const static std::string UNSELECTED_ASSET_PATH;
};

template class RadioButtonWidget<int>;
template class RadioButtonWidget<double>;
template class RadioButtonWidget<float>;
template class RadioButtonWidget<bool>;
template class RadioButtonWidget<std::string>;

#endif
