#pragma once
#include "CCollider.h"

namespace AquaEngine
{
    class CSquareCollider : public CCollider
    {
    public:
        CSquareCollider(Actor* owner, int update_order, const Vector2<float>& size)
            : CCollider(owner, update_order, size)
        {
        }
    };
}
