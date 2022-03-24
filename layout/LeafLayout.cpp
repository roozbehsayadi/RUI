
#include "LeafLayout.h"

void LeafLayout::render(RuiMonitor &monitor, const Rect &rect) const {
  this->BaseLayout::render(monitor, rect);
  widget->draw(monitor,
               {rect.x + xPad * rect.w, rect.y + yPad * rect.h,
                rect.w - 2 * xPad * rect.w, rect.h - 2 * yPad * rect.h},
               {0, 255, 0});
}
