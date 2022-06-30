#ifndef __RUI_H
#define __RUI_H

#include <memory>
#include <utility>
#include <vector>

#include "SDL2/SDL.h"
#include "window/GeneralPage.h"

class BaseWidget;

class RUI {
public:
  static RUI &getInstance();

  RUI(RUI const &) = delete;
  void operator=(RUI const &) = delete;

  void addWindow(GeneralPage *page) { windows[page->slug] = page; }
  bool handleEvents();
  void render();

  SDL_Keycode getPressedKey(const std::string &);
  std::set<SDL_Keymod> getKeyboardModifiers(const std::string &);

  /// return the widget + if it is hidden
  std::pair<std::shared_ptr<BaseWidget>, bool> getWidget(const std::string &) const;

  std::shared_ptr<BaseLayout> getLayout(const std::string &slug) const;

private:
  RUI() {}

  bool isAllWindowsClosed() const;

  // TODO handle without pointers
  std::map<std::string, GeneralPage *> windows;
  // std::vector<GeneralPage *> windows;

  std::vector<std::string> windowsToRender;
  bool firstRender = true;
};

#endif // __RUI_H
