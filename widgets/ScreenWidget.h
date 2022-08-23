#ifndef __SCREEN_WIDGET_H
#define __SCREEN_WIDGET_H

#include "BaseWidget.h"

#include <algorithm>
#include <limits.h>
#include <memory>
#include <vector>

#include "elements/ScreenObject.h"

class ScreenWidget : public BaseWidget {
public:
  ScreenWidget(const std::string &slug) : BaseWidget(slug) {
    type = WIDGET_SCREEN;
    boundary = {0.0, 0.0, 1024.0, 768.0};
  }

  virtual void draw(RuiMonitor &, const Rect &) override;
  virtual void handleClick(int, int) override;
  virtual void handleTextInput(char) override;

  void handleDrag(int, int);
  void handleDrop();

  std::shared_ptr<ScreenObject> getObject(const std::string &) const;
  // slug + valid
  std::pair<const std::string &, bool> getSelectedObjectSlug() const;

  void insertObject(std::shared_ptr<ScreenObject>);
  void removeObject(const std::string &);
  void removeSelectedObject();

  void bringObjectToFront(const std::string &);
  void bringObjectToFrontAllTheWay(const std::string &);
  void sendObjectToBack(const std::string &);
  void sendObjectToBackAllTheWay(const std::string &);

private:
  std::vector<std::shared_ptr<ScreenObject>> objects;

  int currentXShift = 0, currentYShift = 0;
  int xShift = 0, yShift = 0;
  Rect boundary;

  bool objectSelected = false;
  std::shared_ptr<ScreenObject> *selectedObject;
  Rect selectedObjectToDragOriginalPosition;

  int lastClickX = INT_MIN, lastClickY = INT_MIN;
};

#endif // __SCREEN_WIDGET_H
