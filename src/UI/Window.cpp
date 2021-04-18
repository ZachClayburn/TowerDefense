#include "Window.h"

#include <stdexcept>

#include "Renderer.h"

Window::Window(std::function<void(float)> updateFunction,
  int32_t width,
  int32_t height,
  int32_t scale) {
    renderer = std::make_unique<Renderer>(std::move(updateFunction));
    if (!renderer->OnUserCreate()) { throw std::runtime_error("cannot launch main window"); }
    renderer->Construct(width, height, scale, scale);
}

Window::~Window() = default;

int Window::run() { return renderer->Start(); }
