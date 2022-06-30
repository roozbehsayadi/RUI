#ifndef __GENERAL_PAGE_H
#define __GENERAL_PAGE_H

#include <queue>
#include <set>
#include <string>
#include <utility>

#include "layout/ColumnLayout.h"
#include "layout/Container.h"
#include "monitor/RuiMonitor.h"
#include "utils/Rect.h"
#include "widgets/BaseWidget.h"

class GeneralPage {

  friend class RUI;

public:
  // Arguments:
  // - Slug of the main container
  // - Caption of the window
  GeneralPage(const std::string &, const std::string &);

  void render();
  void clear() { monitor.clear(); }
  void update() { monitor.update(); }

  // This function handles all SDL events
  // and returns on SDL_QUIT event.
  void handleEvents(SDL_Event &);

  std::set<SDL_Keymod> getModifiers() const;
  // Returns the oldest key pressed.
  // Does not store more that 100 keys.
  char getPressedKey();
  bool hasPressedKey();

  std::pair<std::shared_ptr<BaseWidget>, bool> getWidget(const std::string &) const;

  std::shared_ptr<BaseLayout> getLayout(const std::string &) const;

  RuiMonitor &getMonitor() { return this->monitor; }
  std::shared_ptr<Container> getGrid() { return this->grid; }

  bool isShown() const { return this->shown; }

private:
  std::string slug;

  RuiMonitor monitor;
  int mouseX = -1, mouseY = -1;

  std::shared_ptr<Container> grid;

  bool shown;

  static void fillModifiers(std::set<SDL_Keymod> &, SDL_Keymod);
  std::queue<SDL_Keycode> pressedKeys;

  void addPressedKey(SDL_Keycode);
};

#endif //__GENERAL_PAGE_H
