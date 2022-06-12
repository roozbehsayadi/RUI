
#include "ScreenWidget.h"

void ScreenWidget::draw(RuiMonitor &monitor, const Rect &showableArea) {
  monitor.drawBox(positionPixel, {0, 0, 0});

  Rect boundaryDrawRect = {
      boundary.x + positionPixel.x + double(xShift + currentXShift),
      boundary.y + positionPixel.y + double(yShift + currentYShift),
      boundary.w,
      boundary.h,
  };
  auto intersectionPair = Geometry::trimRect(boundaryDrawRect, positionPixel);
  if (intersectionPair.second)
    monitor.drawRectangle(intersectionPair.first, {255, 255, 255});

  Rect shiftedPositionPixel = {
      positionPixel.x + xShift + currentXShift,
      positionPixel.y + yShift + currentYShift,
      positionPixel.w,
      positionPixel.h,
  };
  for (auto &object : objects)
    object->draw(shiftedPositionPixel, monitor, showableArea);
}

void ScreenWidget::handleClick(int mouseX, int mouseY) {
  lastClickX = mouseX;
  lastClickY = mouseY;
}

void ScreenWidget::handleTextInput(char input) { throw "not implemented"; }

void ScreenWidget::handleDrag(int mouseX, int mouseY) {
  if (lastClickX == INT_MIN) {
    lastClickX = mouseX;
    lastClickY = mouseY;
  }

  currentXShift = mouseX - lastClickX;
  currentYShift = mouseY - lastClickY;
}

void ScreenWidget::handleDrop() {
  xShift += currentXShift;
  yShift += currentYShift;

  currentXShift = 0;
  currentYShift = 0;

  lastClickX = INT_MIN;
  lastClickY = INT_MIN;
}

std::shared_ptr<ScreenObject> ScreenWidget::getObject(const std::string &slug) const {
  for (auto &object : objects)
    if (object->getSlug() == slug)
      return object;
  return nullptr;
}

void ScreenWidget::insertObject(std::shared_ptr<ScreenObject> object) { this->objects.push_back(object); }

void ScreenWidget::bringObjectToFront(const std::string &slug) {
  if (objects.size() <= 1)
    return;
  for (auto it = objects.begin(); it != objects.end(); it++) {
    auto object = *it;
    if (object->getSlug() == slug) {

      if (it == objects.begin())
        return;

      std::iter_swap(it, it - 1);

      break;
    }
  }
}

void ScreenWidget::bringObjectToFrontAllTheWay(const std::string &slug) {
  if (objects.size() <= 1)
    return;
  for (auto it = objects.begin(); it != objects.end(); it++) {
    auto object = *it;
    if (object->getSlug() == slug) {

      if (it == objects.begin())
        return;

      std::iter_swap(it, objects.begin());

      break;
    }
  }
}

void ScreenWidget::sendObjectToBack(const std::string &slug) {
  if (objects.size() <= 1)
    return;
  for (auto it = objects.begin(); it != objects.end(); it++) {
    auto object = *it;
    if (object->getSlug() == slug) {

      if (it == objects.end() - 1)
        return;

      std::iter_swap(it, it + 1);

      break;
    }
  }
}

void ScreenWidget::sendObjectToBackAllTheWay(const std::string &slug) {
  if (objects.size() <= 1)
    return;
  for (auto it = objects.begin(); it != objects.end(); it++) {
    auto object = *it;
    if (object->getSlug() == slug) {

      if (it == objects.end() - 1)
        return;

      std::iter_swap(it, objects.end() - 1);

      break;
    }
  }
}
