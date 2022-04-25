
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
#include "widgets/RadioButtonWidget.h"
#include "window/GeneralPage.h"

void fillPage(GeneralPage &, const std::string &, const std::string &);
bool showImage1 = true, showImage2 = true, showButton = true, placeholder = false;
int radioVariable = 1;

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

void fillPage(GeneralPage &page, const std::string &index, const std::string &imageSlug) {
  auto grid = page.getGrid();

  auto r = std::make_shared<RowLayout>("row asli" + index, 0.80, 0.20, 0.0, 0.10, 0.10, 0.05);
  auto c = std::make_shared<ColumnLayout>("c1" + index, 0.20, 0.30, 0.0, 0.0, 0.04, 0.25);
  c->addChild(std::make_shared<RowLayout>("row dakheli" + index, 0.80, 0.90, 0.0, 0.0, 0.10, 0.05));
  r->addChild(c);
  auto l = std::make_shared<LeafLayout>("leaf" + index, 0.10, 0.50, 0.1, 0.2, 0.025, 0.25);
  auto button = std::make_shared<ButtonWidget>("button" + index, "Button");
  l->setWidget(button);
  r->addChild(l);

  auto checkboxColumn = std::make_shared<ColumnLayout>("checkbox_column" + index, 0.3, 0.8, 0.0, 0.0, 0.04, 0.0);
  auto checkboxContainer1 = std::make_shared<LeafLayout>("checkbox_container_1", 1.0, 0.24, 0.0, 0.0, 0.0, 0.0);
  auto checkBox1 = std::make_shared<CheckboxWidget>("checkbox_1", showImage1, "show image 1");
  checkboxContainer1->setWidget(checkBox1);
  checkboxColumn->addChild(checkboxContainer1);

  auto checkboxContainer2 = std::make_shared<LeafLayout>("checkbox_container_2", 1.0, 0.24, 0.0, 0.0, 0.0, 0.0);
  auto checkBox2 = std::make_shared<CheckboxWidget>("checkbox_2", showImage2, "show image 2");
  checkboxContainer2->setWidget(checkBox2);
  checkboxColumn->addChild(checkboxContainer2);

  auto checkboxContainer3 = std::make_shared<LeafLayout>("checkbox_container_3", 1.0, 0.24, 0.0, 0.0, 0.0, 0.0);
  auto checkBox3 = std::make_shared<CheckboxWidget>("checkbox_3", showButton, "button visibility");
  checkboxContainer3->setWidget(checkBox3);
  checkboxColumn->addChild(checkboxContainer3);

  auto checkBoxContainer4 = std::make_shared<LeafLayout>("checkbox_container_4", 1.0, 0.24, 0.0, 0.0, 0.0, 0.0);
  auto checkBox4 = std::make_shared<CheckboxWidget>("checkbox_4", placeholder, "nothing");
  checkBox4->setEnabled(false);
  checkBoxContainer4->setWidget(checkBox4);
  checkboxColumn->addChild(checkBoxContainer4);

  r->addChild(checkboxColumn);

  auto radioColumn = std::make_shared<ColumnLayout>("radio_column" + index, 0.3, 0.8, 0.0, 0.0, 0.04, 0.0);
  auto radioContainer1 = std::make_shared<LeafLayout>("radio_container_1", 1.0, 0.25, 0.0, 0.0, 0.0, 0.0);
  auto radio1 = std::make_shared<RadioButtonWidget<int>>("radio_1", radioVariable, "1", 1);
  radioContainer1->setWidget(radio1);
  radioColumn->addChild(radioContainer1);

  auto radioContainer2 = std::make_shared<LeafLayout>("radio_container_2", 1.0, 0.25, 0.0, 0.0, 0.0, 0.0);
  auto radio2 = std::make_shared<RadioButtonWidget<int>>("radio_2", radioVariable, "2", 2);
  radioContainer2->setWidget(radio2);
  radioColumn->addChild(radioContainer2);

  auto radioContainer3 = std::make_shared<LeafLayout>("radio_container_3", 1.0, 0.25, 0.0, 0.0, 0.0, 0.0);
  auto radio3 = std::make_shared<RadioButtonWidget<int>>("radio_3", radioVariable, "3", 3);
  radioContainer3->setWidget(radio3);
  radioColumn->addChild(radioContainer3);

  r->addChild(radioColumn);

  grid->addChild(r);

  auto bigColumn = std::make_shared<ColumnLayout>("big column" + index, 0.80, 0.60, 0.05, 0.05, 0.1, 0.05);
  auto l2 = std::make_shared<LeafLayout>("big leaf" + index, 0.90, 0.90, 0.0, 0.0, 0.0, 0.0);

  auto img = std::make_shared<ImageWidget>(imageSlug, "assets/images/" + imageSlug + ".png");
  l2->setWidget(img);
  bigColumn->addChild(l2);

  grid->addChild(bigColumn);

  auto bigColumn2 = std::make_shared<ColumnLayout>("big column 2" + index, 0.80, 0.60, 0.05, 0.05, 0.1, 0.05);
  auto l3 = std::make_shared<LeafLayout>("big leaf 2" + index, 0.90, 0.90, 0.0, 0.0, 0.0, 0.0);

  auto img2 = std::make_shared<ImageWidget>(imageSlug + "2", "assets/images/" + imageSlug + ".png");
  l3->setWidget(img2);
  bigColumn2->addChild(l3);

  grid->addChild(bigColumn2);
}
