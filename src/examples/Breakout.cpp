#include "olcPixelGameEngine.h"
#include <filesystem>
namespace fs = std::filesystem;

class BreakOut : public olc::PixelGameEngine
{
  public:
    BreakOut() { sAppName = "TUTORIAL - BreakOut Clone"; }

  private:
    static constexpr size_t BLOCKS_W = 24;
    static constexpr size_t BLOCKS_H = 30;
    float fBatPos = 20.0F;
    float fBatWidth = 40.0F;
    olc::vf2d vBall = { 200.0F, 200.0F };
    olc::vf2d vBallVel = { 200.0F, -100.0F };
    float fBatSpeed = 250.0F;
    float fBallRadius = 5.0F;
    olc::vi2d vBlockSize = { 16, 16 };
    std::array<int, BLOCKS_W * BLOCKS_H> blocks{};

    std::unique_ptr<olc::Sprite> sprTile;

  public:
    bool OnUserCreate() override {
        for (size_t y = 0; y < BLOCKS_H; y++) {
            for (size_t x = 0; x < BLOCKS_W; x++) {
                blocks[y * BLOCKS_W + x] = (x == 0 || y == 0 || x == BLOCKS_W - 1) ? 10 : 0;

                if (x > 2 && x <= 20 && y > 3 && y <= 5) { blocks[y * BLOCKS_W + x] = 1; }
                if (x > 2 && x <= 20 && y > 5 && y <= 7) { blocks[y * BLOCKS_W + x] = 2; }
                if (x > 2 && x <= 20 && y > 7 && y <= 9) { blocks[y * BLOCKS_W + x] = 3; }
            }
        }

        // Load the sprite
        const fs::path resourceDir{RESOURCE_DIR};
        auto spriteFile = resourceDir / "examples/tut_tiles.png";
        sprTile = std::make_unique<olc::Sprite>(spriteFile.string());

        return true;
    }

    bool OnUserUpdate(float /*fElapsedTime*/) override {
        // Draw Screen
        Clear(olc::DARK_BLUE);
        SetPixelMode(olc::Pixel::MASK);// Dont draw pixels which have any transparency
        for (size_t y = 0; y < BLOCKS_H; y++) {
            for (size_t x = 0; x < BLOCKS_W; x++) {
                olc::vi2d tileLocation(static_cast<int>(x), static_cast<int>(y));
                switch (blocks[y * BLOCKS_W + x]) {
                case 0:// Do nothing
                    break;
                case 10:// Draw Boundary
                    DrawPartialSprite(tileLocation * vBlockSize,
                      sprTile.get(),
                      olc::vi2d(0, 0) * vBlockSize,
                      vBlockSize);
                    break;
                case 1:// Draw Red Block
                    DrawPartialSprite(tileLocation * vBlockSize,
                      sprTile.get(),
                      olc::vi2d(1, 0) * vBlockSize,
                      vBlockSize);
                    break;
                case 2:// Draw Green Block
                    DrawPartialSprite(tileLocation * vBlockSize,
                      sprTile.get(),
                      olc::vi2d(2, 0) * vBlockSize,
                      vBlockSize);
                    break;
                case 3:// Draw Yellow Block
                    DrawPartialSprite(tileLocation * vBlockSize,
                      sprTile.get(),
                      olc::vi2d(3, 0) * vBlockSize,
                      vBlockSize);
                    break;
                }
            }
        }
        SetPixelMode(olc::Pixel::NORMAL);// Draw all pixels


        return true;
    }
};

int main() {
    BreakOut demo;
    if (demo.Construct(512, 480, 2, 2)) demo.Start();
    return 0;
}
