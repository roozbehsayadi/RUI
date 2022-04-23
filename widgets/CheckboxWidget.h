#ifndef __CHECKBOX_WIDGET_H
#define __CHECKBOX_WIDGET_H

#include "widgets/BaseWidget.h"

#include <algorithm>

class CheckboxWidget : public BaseWidget {
public:
  CheckboxWidget(const std::string &slug, bool &variable,
                 const std::string &label)
      : BaseWidget(slug), label(label), variable(variable) {}

protected:
  virtual void draw(RuiMonitor &, const Rect &) override;
  virtual void handleClick(int, int) override;

  std::string label;
  bool &variable;

  SDL_Texture *boxTexture = nullptr;

  const static std::string ASSET_PATH;
};

#endif // __CHECKBOX_WIDGET_H
