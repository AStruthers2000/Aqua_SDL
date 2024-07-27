#pragma once

#include "Vector.h"

namespace AquaEngine
{
    const Vector2<float> default_position { 0, 0 };
    const Vector2<float> default_scale { 0, 0 };
    const Vector2<float> default_rotation { 0, 0 };

    class Transform
    {
    public:
        Transform() : position_(default_position), scale_(default_scale), rotation_(default_rotation) {}
        Transform(const Vector2<float>& position) : position_(position), scale_(default_scale), rotation_(default_rotation) {}
        Transform(const Vector2<float>& position, const Vector2<float>& scale) : position_(position), scale_(scale), rotation_(default_rotation) {}
        Transform(const Vector2<float>& position, const Vector2<float>& scale, const Vector2<float>& rotation) : position_(position), scale_(scale), rotation_(rotation) {}
        //Transform(const Vector2<float>& position, const Vector2<float>& scale, const Vector2<float>& rotation, const Bounds& bounds) : position_(position), scale_(scale), rotation_(rotation), bounds_(bounds) {}

        Vector2<float> GetTransformPosition() const { return position_; }
        const Vector2<float>* GetTransformPositionRef() const { return &position_; }
        Vector2<float> GetTransformScale() const { return scale_; }
        Vector2<float> GetTransformRotation() const { return rotation_; }
        //Bounds GetTransformBounds() const { return bounds_; }

        void SetTransformPosition(const Vector2<float>& new_position)
        {
            position_ = new_position;
        }
        void SetTransformScale(const Vector2<float>& new_scale) { scale_ = new_scale; }
        void SetTransformRotation(const Vector2<float>& new_rotation) { rotation_ = new_rotation; }
        //void SetTransformBounds(const Bounds& new_bounds) { bounds_ = new_bounds; }
        
    private:
        Vector2<float> position_;
        Vector2<float> scale_;
        Vector2<float> rotation_;
        //Bounds bounds_;
    };

    
}
