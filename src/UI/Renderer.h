
#ifndef MYPROJECT_RENDERER_H
#define MYPROJECT_RENDERER_H

#include <functional>

#include "olcPixelGameEngine.h"

class Renderer : public olc::PixelGameEngine
{
    std::function<void(float)> updateFunction;
  public:
    explicit Renderer(std::function<void(float)> onUpdate);
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;

};


#endif// MYPROJECT_RENDERER_H
