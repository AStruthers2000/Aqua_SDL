#pragma once
#include "Component/Component.h"
#include "Math/Bounds.h"
#include "Math/Point.h"

namespace AquaEngine
{
    class CCollider : public Component
    {
    public:
        CCollider(Actor* owner, int update_order, const Vector2<float>& size)
            : Component(owner, update_order)
        {
            bounds_ = {owner->GetActorPositionRef(), size.x, size.y};
        }

        void TickComponent(float delta_time) override;
        Bounds GetBounds() const { return bounds_; }
        Bounds* GetBoundsRef() { return &bounds_; }
        [[deprecated]] void UpdateBounds(const Vector2<float>& new_bounds)
        {
            bounds_.SetSize(new_bounds);
        }

    protected:
        [[nodiscard]] bool Contains (const Point& p) const
        {
            const auto point_location = p.GetPointLocation();
            const bool inside_x = bounds_.GetMin().x >= point_location.x && point_location.x <= bounds_.GetMax().x;
            const bool inside_y = bounds_.GetMin().y >= point_location.y && point_location.y <= bounds_.GetMax().y;
            return inside_x && inside_y;
        }

        

    private:
        Bounds bounds_;
    };
}
