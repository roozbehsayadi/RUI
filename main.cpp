
#include <iostream>
#include <stdlib.h>

#include "GeneralPage.h"
#include "layout/ColumnLayout.h"
#include "layout/LeafLayout.h"
#include "layout/RowLayout.h"
#include "utils/Rect.h"
#include "widgets/ButtonWidget.h"

int main() {

  GeneralPage page("rui");
  auto grid = page.getGrid();
  RowLayout *r = new RowLayout(0.80, 0.20, 0.0, 0.10, 0.10, 0.05);
  ColumnLayout *c = new ColumnLayout(0.20, 0.30, 0.0, 0.0, 0.04, 0.25);
  c->addChild(new RowLayout(0.80, 0.90, 0.0, 0.0, 0.10, 0.05));
  r->addChild(c);
  r->addChild(new ColumnLayout(0.20, 0.70, 0.0, 0.0, 0.04, 0.05));
  r->addChild(new ColumnLayout(0.20, 0.60, 0.0, 0.0, 0.04, 0.10));
  LeafLayout *l = new LeafLayout(0.10, 0.10, 0.35, 0.25, 0.025, 0.35);
  ButtonWidget button;
  l->setWidget(button);
  r->addChild(l);
  grid.addChild(r);
  grid.render(page.getMonitor(), Rect{0.0, 0.0, 1920, 1080});

  page.getMonitor().update();

  page.getMonitor().delay(2000);

  return EXIT_SUCCESS;
}
