#pragma once
#include "Vector.h"

namespace AquaEngine
{
    class Point
    {
    public:
        Point() = default;
        Point(float value) : location_({value, value}) {}
        Point(float x, float y) : location_({x, y}) {}

        Vector2<float> GetPointLocation() const { return location_; };
    private:
        Vector2<float> location_;
    };
}
