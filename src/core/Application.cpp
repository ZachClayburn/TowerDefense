#include "Application.h"

Application::Application()
  : window(std::bind(&Application::onUpdate, this, std::placeholders::_1), 1920, 1080) {}

void Application::onUpdate(float /*dt*/) {
    scene.ge
}

void Application::run() { window.run(); }
