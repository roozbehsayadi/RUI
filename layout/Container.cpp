
#include "Container.h"

#include <algorithm>

#include "utils/Geometry.h"

const int Container::SCROLL_SPEED = 30;

std::pair<std::shared_ptr<BaseWidget>, bool> Container::getWidget(const std::string &slug) const {
  for (auto &child : children) {
    auto returnedWidget = child->getWidget(slug);
    if (returnedWidget.first != nullptr)
      return std::make_pair(returnedWidget.first, returnedWidget.second | this->hidden);
  }
  return std::make_pair<std::shared_ptr<BaseWidget>, bool>(nullptr, false);
}

std::shared_ptr<BaseLayout> Container::getLayout(const std::string &slug) const {
  for (auto &child : children) {
    if (child->getSlug() == slug)
      return child;
    auto childResult = child->getLayout(slug);
    if (childResult != nullptr)
      return childResult;
  }
  return nullptr;
}

void Container::handleClick(int mouseX, int mouseY) {
  if (hidden)
    return;
  for (auto &child : children)
    child->removeFocus();
  if (Geometry::isPointInsideRect(mouseX, mouseY, positionPixel))
    for (auto &child : children) {
      child->handleClick(mouseX, mouseY);
    }
}

bool Container::handleScroll(int scrollAmount, int mouseX, int mouseY) {
  if (hidden)
    return false;
  bool somethingAffected = false;
  if (Geometry::isPointInsideRect(mouseX, mouseY, positionPixel)) {
    for (auto &child : children) {
      somethingAffected |= child->handleScroll(scrollAmount, mouseX, mouseY);
    }
  }

  return somethingAffected;
}

bool Container::handleTextInput(char key) {
  if (hidden)
    return false;
  for (auto &child : children)
    if (child->handleTextInput(key))
      return true;
  return false;
}

bool Container::hasFocusedWidget() const {
  if (hidden)
    return false;
  for (auto &child : children)
    if (child->hasFocusedWidget())
      return true;
  return false;
}

void Container::render(RuiMonitor &monitor, const Rect &showableArea) {
  if (!this->hidden) {
    monitor.drawRectangle(positionPixel, {255, 0, 0});
    for (auto child : children) {
      Rect childRect{positionPixel.x + positionPixel.w * xPad + positionPixel.w * child->getXMargin(),
                     positionPixel.y + positionPixel.h * yPad + positionPixel.h * child->getYMargin(),
                     positionPixel.w * child->getWidth(), positionPixel.h * child->getHeight()};
      child->setPositionPixel(childRect);
      child->render(monitor, showableArea);
    }
  }
}

std::vector<std::shared_ptr<BaseLayout>> Container::getVisibleChildren() {
  std::vector<std::shared_ptr<BaseLayout>> visibleChildren;
  std::copy_if(children.begin(), children.end(), std::back_inserter(visibleChildren),
               [](std::shared_ptr<BaseLayout> child) { return !child->isHidden(); });
  return visibleChildren;
}

void Container::setScrollableAndScrollSpace(int availableLength, int &thisWay, int &thatWay) {
  auto visibleChildren = getVisibleChildren();
  if (visibleChildren.size() != 0) {
    auto childrenTotalLength = totalChildrenLength(visibleChildren);
    scrollable = childrenTotalLength > availableLength * (1 + BaseLayout::SCROLLABLE_EPSILON);
    if (initialDistance < 0)
      thatWay = -initialDistance;
    else
      thatWay = 0;
    auto lastChild = visibleChildren.at(visibleChildren.size() - 1);
    if (getLayoutEnd(lastChild, availableLength) > this->getLayoutEnd())
      thisWay = getLayoutEnd(lastChild, availableLength) - this->getLayoutEnd();
    else
      thisWay = 0;
  }
}

void Container::removeFocus() {
  for (auto &child : children)
    child->removeFocus();
}
