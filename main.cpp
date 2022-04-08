
#include <memory>
#include <stdlib.h>

#include "window/GeneralPage.h"
#include "layout/ColumnLayout.h"
#include "layout/LeafLayout.h"
#include "layout/RowLayout.h"
#include "utils/Rect.h"
#include "widgets/ButtonWidget.h"
#include "RUI.h"

void fillPage(GeneralPage &);

int main() {

  GeneralPage page("rui");
  fillPage(page);

  GeneralPage page2("rui2");
  fillPage(page2);

  RUI rui;
  rui.addWindow(&page);
  rui.addWindow(&page2);

  rui.start();

  return EXIT_SUCCESS;
}

void fillPage(GeneralPage &page) {
  auto &grid = page.getGrid();
  std::shared_ptr<RowLayout> r =
      std::make_shared<RowLayout>(0.80, 0.20, 0.0, 0.10, 0.10, 0.05);
  std::shared_ptr<ColumnLayout> c =
      std::make_shared<ColumnLayout>(0.20, 0.30, 0.0, 0.0, 0.04, 0.25);
  c->addChild(std::make_shared<RowLayout>(0.80, 0.90, 0.0, 0.0, 0.10, 0.05));
  r->addChild(c);
  r->addChild(std::make_shared<ColumnLayout>(0.20, 0.70, 0.0, 0.0, 0.04, 0.05));
  r->addChild(std::make_shared<ColumnLayout>(0.20, 0.60, 0.0, 0.0, 0.04, 0.20));
  std::shared_ptr<LeafLayout> l =
      std::make_shared<LeafLayout>(0.10, 0.50, 0.1, 0.2, 0.025, 0.25);
  std::shared_ptr<ButtonWidget> button =
      std::make_shared<ButtonWidget>("Button");
  l->setWidget(button);
  r->addChild(l);
  grid.addChild(r);
}
