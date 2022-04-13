
#include "GeneralPage.h"

GeneralPage::GeneralPage(const std::string &slug, const std::string &caption) {
  monitor.setCaption(caption);

  grid = std::make_shared<ColumnLayout>(slug, 1.0, 1.0);

  shown = true;
}

void GeneralPage::render() {
  auto monitorSize = monitor.getMonitorSize();
  grid->setPositionPixel(
      {0.0, 0.0, double(monitorSize.first), double(monitorSize.second)});
  grid->render(monitor);
}

void GeneralPage::handleEvents(SDL_Event &event) {
  if (event.window.windowID != SDL_GetWindowID(monitor.window))
    return;
  if (event.type == SDL_WINDOWEVENT) {
    switch (event.window.event) {
    case SDL_WINDOWEVENT_SHOWN:
      shown = true;
      break;

    case SDL_WINDOWEVENT_HIDDEN:
      shown = false;
      break;

    case SDL_WINDOWEVENT_EXPOSED:
      monitor.update();
      break;

    case SDL_WINDOWEVENT_CLOSE:
      SDL_HideWindow(monitor.window);
      break;

    default:
      break;
    }
  } else if (event.type == SDL_MOUSEBUTTONDOWN) {
    grid->handleClick(event.button.x, event.button.y);
  }
}

bool GeneralPage::isClicked(const std::string &slug) {
  return grid->isClicked(slug);
}

bool GeneralPage::setLayoutHidden(const std::string &slug, bool hidden) {
  return grid->setLayoutHidden(slug, hidden);
}

bool GeneralPage::setEnabledWidget(const std::string &slug, bool enabled) {
  return grid->setEnabledWidget(slug, enabled);
}
