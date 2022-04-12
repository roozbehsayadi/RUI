
#include <memory>
#include <stdlib.h>

#include "RUI.h"
#include "layout/ColumnLayout.h"
#include "layout/LeafLayout.h"
#include "layout/RowLayout.h"
#include "utils/Rect.h"
#include "widgets/ButtonWidget.h"
#include "widgets/ImageWidget.h"
#include "window/GeneralPage.h"

void fillPage(GeneralPage &, const std::string &, const std::string &);

int main() {

  GeneralPage page("rui");
  fillPage(page, "button1", "img1");

  GeneralPage page2("rui2");
  fillPage(page2, "button2", "img2");

  RUI rui;
  rui.addWindow(&page);
  rui.addWindow(&page2);

  rui.render();
  bool quit = false;
  while (!quit) {
    quit = rui.handleEvents();

    // do your stuff here. for example:
    if (rui.isClicked("button1"))
      std::cout << "Button 1 is clicked!" << std::endl;
    if (rui.isClicked("button2"))
      std::cout << "Button 2 is clicked!" << std::endl;

    rui.render();
  }

  return EXIT_SUCCESS;
}

void fillPage(GeneralPage &page, const std::string &buttonSlug,
              const std::string &imageSlug) {
  auto grid = page.getGrid();

  auto r = std::make_shared<RowLayout>(0.80, 0.20, 0.0, 0.10, 0.10, 0.05);
  auto c = std::make_shared<ColumnLayout>(0.20, 0.30, 0.0, 0.0, 0.04, 0.25);
  c->addChild(std::make_shared<RowLayout>(0.80, 0.90, 0.0, 0.0, 0.10, 0.05));
  r->addChild(c);
  r->addChild(std::make_shared<ColumnLayout>(0.20, 0.70, 0.0, 0.0, 0.04, 0.05));
  r->addChild(std::make_shared<ColumnLayout>(0.20, 0.60, 0.0, 0.0, 0.04, 0.20));
  auto l = std::make_shared<LeafLayout>(0.10, 0.50, 0.1, 0.2, 0.025, 0.25);
  auto button = std::make_shared<ButtonWidget>(buttonSlug, "Button");
  l->setWidget(button);
  r->addChild(l);
  grid->addChild(r);

  auto bigColumn =
      std::make_shared<ColumnLayout>(0.80, 0.60, 0.05, 0.05, 0.1, 0.05);
  auto l2 = std::make_shared<LeafLayout>(0.90, 0.90, 0.0, 0.0, 0.0, 0.0);
  bigColumn->addChild(l2);

  auto img = std::make_shared<ImageWidget>(imageSlug, "assets/images/" +
                                                          imageSlug + ".png");
  l2->setWidget(img);
  grid->addChild(bigColumn);
}
