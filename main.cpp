
#include <memory>
#include <stdlib.h>

#include "RUI.h"
#include "layout/ColumnLayout.h"
#include "layout/LeafLayout.h"
#include "layout/RowLayout.h"
#include "utils/Rect.h"
#include "widgets/ButtonWidget.h"
#include "widgets/CheckboxWidget.h"
#include "widgets/ImageWidget.h"
#include "window/GeneralPage.h"

void fillPage(GeneralPage &, const std::string &, const std::string &);
bool showImage1 = true, showImage2 = true, showButton = true,
     placeholder = false;

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
    auto buttonLeaf = rui.getLayout("leaf1");
    auto leaf1 = rui.getLayout("big leaf1");
    auto leaf2 = rui.getLayout("big leaf 21");
    if (button1->isClicked()) {
      showImage1 = true;
      showImage2 = true;
    }
    leaf1->setHidden(!showImage1);
    leaf2->setHidden(!showImage2);
    buttonLeaf->setHidden(!showButton);

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

  auto cTemp = std::make_shared<ColumnLayout>("c_temp" + index, 0.3, 0.8, 0.0,
                                              0.0, 0.04, 0.0);
  auto checkBoxContainer1 = std::make_shared<LeafLayout>(
      "checkbox_container_1", 1.0, 0.24, 0.0, 0.0, 0.0, 0.0);
  auto checkBox1 = std::make_shared<CheckboxWidget>("checkbox_1", showImage1,
                                                    "show image 1");
  checkBoxContainer1->setWidget(checkBox1);
  cTemp->addChild(checkBoxContainer1);

  auto checkBoxContainer2 = std::make_shared<LeafLayout>(
      "checkbox_container_2", 1.0, 0.24, 0.0, 0.0, 0.0, 0.0);
  auto checkBox2 = std::make_shared<CheckboxWidget>("checkbox_2", showImage2,
                                                    "show image 2");
  checkBoxContainer2->setWidget(checkBox2);
  cTemp->addChild(checkBoxContainer2);

  auto checkBoxContainer3 = std::make_shared<LeafLayout>(
      "checkbox_container_3", 1.0, 0.24, 0.0, 0.0, 0.0, 0.0);
  auto checkBox3 = std::make_shared<CheckboxWidget>("checkbox_3", showButton,
                                                    "button visibility");
  checkBoxContainer3->setWidget(checkBox3);
  cTemp->addChild(checkBoxContainer3);

  auto checkBoxContainer4 = std::make_shared<LeafLayout>(
      "checkbox_container_4", 1.0, 0.24, 0.0, 0.0, 0.0, 0.0);
  auto checkBox4 =
      std::make_shared<CheckboxWidget>("checkbox_4", placeholder, "nothing");
  checkBox4->setEnabled(false);
  checkBoxContainer4->setWidget(checkBox4);
  cTemp->addChild(checkBoxContainer4);

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
