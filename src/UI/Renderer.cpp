#include "Renderer.h"

#include <utility>

Renderer::Renderer(std::function<void(float)> onUpdate) : updateFunction(std::move(onUpdate)) {}

bool Renderer::OnUserCreate() { return true; }

bool Renderer::OnUserUpdate(float fElapsedTime) {
    updateFunction(fElapsedTime);
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
