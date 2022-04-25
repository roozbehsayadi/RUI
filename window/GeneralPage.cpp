
#include "GeneralPage.h"

GeneralPage::GeneralPage(const std::string &slug, const std::string &caption) {
  monitor.setCaption(caption);

  grid = std::make_shared<ColumnLayout>(slug, 1.0, 1.0);

  shown = true;
}

void GeneralPage::render() {
  auto monitorSize = monitor.getMonitorSize();
  Rect monitorRect{0.0, 0.0, double(monitorSize.first), double(monitorSize.second)};
  grid->setPositionPixel(monitorRect);
  grid->render(monitor, monitorRect);
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
  } else if (event.type == SDL_MOUSEMOTION) {
    SDL_GetMouseState(&mouseX, &mouseY);
  } else if (event.type == SDL_MOUSEWHEEL) {
    grid->handleScroll(event.wheel.y, mouseX, mouseY);
  }
}

std::pair<std::shared_ptr<BaseWidget>, bool> GeneralPage::getWidget(const std::string &slug) const {
  return grid->getWidget(slug);
}

std::shared_ptr<BaseLayout> GeneralPage::getLayout(const std::string &slug) const { return grid->getLayout(slug); }
