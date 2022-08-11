
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
  for (auto &object : objects) {
    object->draw(shiftedPositionPixel, monitor, showableArea);
    if (objectSelected && object->getSlug() == selectedObject->get()->getSlug()) {
      Rect tempRect = object->getPositionPixel();
      tempRect.x += positionPixel.x;
      tempRect.y += positionPixel.y;
      monitor.drawRectangle(tempRect, {255, 255, 255});
    }
  }
}

void ScreenWidget::handleClick(int mouseX, int mouseY) {

  if (!Geometry::isPointInsideRect(mouseX, mouseY, positionPixel))
    return;

  for (auto &object : objects) {

    auto objectPosition = object->getPositionPixel();
    Rect temp = {positionPixel.x + objectPosition.x + xShift, positionPixel.y + objectPosition.y + yShift,
                 objectPosition.w, objectPosition.h};

    if (Geometry::isPointInsideRect(mouseX, mouseY, temp)) {
      objectSelected = true;
      selectedObject = &object;
      selectedObjectToDragOriginalPosition = selectedObject->get()->getPositionPixel();
      return;
    }
  }

  objectSelected = false;

  lastClickX = mouseX;
  lastClickY = mouseY;
}

void ScreenWidget::handleTextInput(char input) { throw "not implemented"; }

void ScreenWidget::handleDrag(int mouseX, int mouseY) {
  if (lastClickX == INT_MIN) {
    lastClickX = mouseX;
    lastClickY = mouseY;
  }

  if (objectSelected) {
    selectedObject->get()->setPositionPixel({
        selectedObjectToDragOriginalPosition.x + (mouseX - lastClickX),
        selectedObjectToDragOriginalPosition.y + (mouseY - lastClickY),
        selectedObjectToDragOriginalPosition.w,
        selectedObjectToDragOriginalPosition.h,
    });
  } else {
    currentXShift = mouseX - lastClickX;
    currentYShift = mouseY - lastClickY;
  }
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

void ScreenWidget::removeObject(const std::string &slug) {
  for (auto it = objects.begin(); it != objects.end(); it++) {
    if (it->get()->getSlug() == slug) {
      it = objects.erase(it);
      break;
    }
  }
}

void ScreenWidget::removeSelectedObject() {
  if (!objectSelected)
    return;
  for (auto it = objects.begin(); it != objects.end(); it++) {
    if (it->get()->getSlug() == selectedObject->get()->getSlug()) {
      it = objects.erase(it);
      break;
    }
  }
}

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
