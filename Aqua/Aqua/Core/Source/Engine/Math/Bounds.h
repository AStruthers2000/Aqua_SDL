#pragma once
#include <iostream>
#include "Vector.h"

namespace AquaEngine
{
    class Bounds
    {
    public:
        Bounds() = default;
        Bounds(const Vector2<float>* center, const float width = 0.f, const float height = 0.f)
        {
            if(center == nullptr)
            {
                std::cerr << "[Bounds::Bounds]:\tInitialized Bounds object without passing reference to actor center" << std::endl;
            }
            center_ = center;
            //SetSize({width, height});
            UpdateWidth(width);
            UpdateHeight(height);
        }

        //[[nodiscard]] int GetWidth() const { return width_; }
        //[[nodiscard]] int GetHeight() const { return height_; }
        //[[nodiscard]] int GetHalfWidth() const { return half_width_; }
        //[[nodiscard]] int GetHalfHeight() const { return half_height_; }

        //void SetBoundsCenter(const Vector2<float>& new_center) { center_ = new_center; }

        void SetSize(const Vector2<float>& new_size)
        {
            UpdateWidth(new_size.x);
            UpdateHeight(new_size.y);
        }

        

        Vector2<float> GetMin() const { return min_; }
        Vector2<float> GetMax() const { return max_; }
        Vector2<float> GetSize() const { return size_; }
        Vector2<float> GetHalfSize() const { return half_size_; }
        

    private:
        void UpdateWidth(const float new_width)
        {
            size_.x = new_width;
            half_size_.x = size_.x / 2.f;
            UpdateMinMax();
        }

        void UpdateHeight(const float new_height)
        {
            size_.y = new_height;
            half_size_.y = size_.y / 2.f;
            UpdateMinMax();
        }

        void UpdateMinMax()
        {
            min_ = *center_ - half_size_;
            max_ = *center_ + half_size_;
        }

        const Vector2<float>* center_;
        //Vector2<float> extents_;
        Vector2<float> max_;
        Vector2<float> min_;
        Vector2<float> size_;
        Vector2<float> half_size_;
    };
}
