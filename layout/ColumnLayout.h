#ifndef __COLUMN_LAYOUT_H
#define __COLUMN_LAYOUT_H

#include <algorithm>

#include "Container.h"
#include "monitor/RuiMonitor.h"
#include "utils/Geometry.h"
#include "utils/Rect.h"

class ColumnLayout : public Container {
public:
  ColumnLayout(const std::string &slug) : ColumnLayout(slug, 0.0, 0.0) {}
  ColumnLayout(const std::string &slug, double width, double height, double xPad = 0.0, double yPad = 0.0,
               double xMargin = 0.0, double yMargin = 0.0)
      : Container(slug, width, height, xPad, yPad, xMargin, yMargin) {
    type = LAYOUT_COLUMN;
  }

  virtual bool handleScroll(int, int, int) override;

  virtual void render(RuiMonitor &, const Rect &) override;

protected:
  virtual double totalChildrenLength(std::vector<std::shared_ptr<BaseLayout>> &) const override;

  virtual double getLayoutEnd(std::shared_ptr<BaseLayout> &, int = 0) const override;
  virtual double getLayoutEnd(int = 0) const override;

private:
  int availableScrollSpaceUp = 0, availableScrollSpaceDown = 0;
};

#endif // __COLUMN_LAYOUT_H
