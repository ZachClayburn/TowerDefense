
#ifndef MYPROJECT_RENDERER_H
#define MYPROJECT_RENDERER_H

#include "olcPixelGameEngine.h"

class Renderer : public olc::PixelGameEngine
{
  public:
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;

  private:
    olc::Pixel getPixelAt(int32_t x, int32_t y);
};


#endif// MYPROJECT_RENDERER_H
