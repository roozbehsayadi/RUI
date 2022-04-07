
#include "ButtonWidget.h"

void ButtonWidget::draw(RuiMonitor &monitor, const Rect &rect,
                        const Color &color) {
  monitor.drawRectangle(rect, color);
  monitor.drawText(rect, color, caption);
}
