
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

  GeneralPage page("main_1", "rui");
  fillPage(page, "1", "img1");

  // GeneralPage page2("main_2", "rui2");
  // fillPage(page2, "2", "img2");

  RUI rui;
  rui.addWindow(&page);
  // rui.addWindow(&page2);

  rui.render();
  bool quit = false;
  while (!quit) {
    quit = rui.handleEvents();

    // do your stuff here. for example:
    auto button1 = rui.getWidget("button1").first;
    //  button2 = rui.getWidget("button2").first;
    auto leaf1 = rui.getLayout("big leaf1");
    if (button1->isClicked()) {
      if (leaf1->isHidden())
        leaf1->show();
      else
        leaf1->hide();
    }
    if (button1->isClicked())
      if (leaf1->isHidden())
        leaf1->show();
      else
        leaf1->hide();
    // if (button2->isClicked()) {
    //   if (button1->isEnabled())
    //     button1->setEnabled(false);
    //   else
    //     button1->setEnabled(true);
    // }

    rui.render();
  }

  return EXIT_SUCCESS;
}

void fillPage(GeneralPage &page, const std::string &index,
              const std::string &imageSlug) {
  auto grid = page.getGrid();

  auto r = std::make_shared<RowLayout>("row asli" + index, 0.80, 0.20, 0.0,
                                       0.10, 0.10, 0.05);
  auto c = std::make_shared<ColumnLayout>("c1" + index, 0.20, 0.30, 0.0, 0.0,
                                          0.04, 0.25);
  auto cTemp = std::make_shared<ColumnLayout>("c_temp" + index, 0.3, 0.3, 0.0,
                                              0.0, 0.04, 0.25);
  c->addChild(std::make_shared<RowLayout>("row dakheli" + index, 0.80, 0.90,
                                          0.0, 0.0, 0.10, 0.05));
  r->addChild(c);
  r->addChild(std::make_shared<ColumnLayout>("c2" + index, 0.20, 0.70, 0.0, 0.0,
                                             0.04, 0.05));
  r->addChild(std::make_shared<ColumnLayout>("c3" + index, 0.20, 0.60, 0.0, 0.0,
                                             0.04, 0.20));
  r->addChild(std::make_shared<ColumnLayout>("c4" + index, 0.20, 0.60, 0.0, 0.0,
                                             0.04, 0.20));
  auto l = std::make_shared<LeafLayout>("leaf" + index, 0.10, 0.50, 0.1, 0.2,
                                        0.025, 0.25);
  auto button = std::make_shared<ButtonWidget>("button" + index, "Button");
  l->setWidget(button);
  r->addChild(l);
  r->addChild(cTemp);
  grid->addChild(r);

  auto bigColumn = std::make_shared<ColumnLayout>("big column" + index, 0.80,
                                                  0.60, 0.05, 0.05, 0.1, 0.05);
  auto l2 = std::make_shared<LeafLayout>("big leaf" + index, 0.90, 0.90, 0.0,
                                         0.0, 0.0, 0.0);

  auto img = std::make_shared<ImageWidget>(imageSlug, "assets/images/" +
                                                          imageSlug + ".png");
  l2->setWidget(img);
  bigColumn->addChild(l2);

  grid->addChild(bigColumn);

  auto bigColumn2 = std::make_shared<ColumnLayout>("big column 2" + index, 0.80,
                                                   0.60, 0.05, 0.05, 0.1, 0.05);
  auto l3 = std::make_shared<LeafLayout>("big leaf 2" + index, 0.90, 0.90, 0.0,
                                         0.0, 0.0, 0.0);

  auto img2 = std::make_shared<ImageWidget>(
      imageSlug + "2", "assets/images/" + imageSlug + ".png");
  l3->setWidget(img2);
  bigColumn2->addChild(l3);

  grid->addChild(bigColumn2);
}
