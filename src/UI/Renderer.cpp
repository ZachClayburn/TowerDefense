#include "Renderer.h"

#include <limits>
#include <cmath>
#include <numbers>
#include <cassert>

bool Renderer::OnUserCreate() { return true; }

bool Renderer::OnUserUpdate(float /*fElapsedTime*/) {
    for (int32_t x = 0; x < ScreenWidth(); x++) {
        for (int32_t y = 0; y < ScreenHeight(); y++) {
            auto pixel = getPixelAt(x, y);
            Draw(x, y, pixel);
        }
    }
    return true;
}

template<class InType, class OutType> class RangeMapper
{
    InType iLow;
    InType iHigh;
    OutType oLow;
    OutType oHigh;

  public:
    constexpr RangeMapper(InType inLow, InType inHigh, OutType outLow, OutType outHigh)
      : iLow{ inLow }, iHigh{ inHigh }, oLow{ outLow }, oHigh{ outHigh } {}

    constexpr OutType operator()(InType inValue) {
        const auto floatIn =
          static_cast<long double>(inValue - iLow) / static_cast<long double>(iHigh);
        return static_cast<OutType>(floatIn * (oHigh - oLow)) + oLow;
    }

    template<class MapFunc> constexpr OutType operator()(MapFunc f, InType inValue) {
        const auto floatIn =
          static_cast<long double>(inValue - iLow) / static_cast<long double>(iHigh);
        const long double transformedIn = f(floatIn);
        return static_cast<OutType>(transformedIn * (oHigh - oLow)) + oLow;
    }
};


olc::Pixel Renderer::getPixelAt(int32_t x, int32_t /*y*/) {
    constexpr int32_t period = 50;
    RangeMapper<int32_t, uint8_t> widthFlattener
      [[maybe_unused]]{ 0, period - 1, 0, std::numeric_limits<uint8_t>::max() };
    RangeMapper<int32_t, uint8_t> heightFlattener
      [[maybe_unused]]{ 0, period - 1, 0, std::numeric_limits<uint8_t>::max() };

    auto transform = [](long double in) {
        assert(0 <= in && in <= 1);
        return std::sin(2 * std::numbers::pi_v<long double> * in);
    };
    auto red = widthFlattener(transform, x % period);
    auto green = widthFlattener(transform, x % period);
    auto blue = widthFlattener(transform, x % period);

    return { red, green, blue };
}
