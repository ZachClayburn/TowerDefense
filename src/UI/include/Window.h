
#ifndef MYPROJECT_WINDOW_H
#define MYPROJECT_WINDOW_H

#include <memory>
#include <functional>

class Renderer;

class Window
{
    std::unique_ptr<Renderer> renderer;

  public:
    Window(std::function<void(float)> updateFunction,
      int32_t width,
      int32_t height,
      int32_t scale = 1);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    Window(Window&&) = default;
    Window& operator=(Window&&) = default;
    int run();
};


#endif// MYPROJECT_WINDOW_H
