
#ifndef MYPROJECT_APPLICATION_H
#define MYPROJECT_APPLICATION_H

#include "Scene.h"
#include "Window.h"

class Application
{
    Scene scene;
    Window window;

  public:
    Application();

    void run();
  private:
    void onUpdate(float dt);
};


#endif// MYPROJECT_APPLICATION_H
