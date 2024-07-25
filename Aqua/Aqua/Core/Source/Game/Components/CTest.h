#pragma once

#include "Component/Component.h"

class CTest : public AquaEngine::Component
{
public:
    CTest(AquaEngine::Actor* owner, int update_order)
        : Component(owner, update_order)
    {

    }

    ~CTest() override;
    void TickComponent(float delta_time) override;
};
