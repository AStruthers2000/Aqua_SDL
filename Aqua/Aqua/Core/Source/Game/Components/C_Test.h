#pragma once

#include "Component/Component.h"
#include <iostream>

class C_Test : public AquaEngine::Component
{
public:
    C_Test(AquaEngine::Actor* owner, int update_order)
        : Component(owner, update_order)
    {
        std::cout << "Created test component" << std::endl;
    }

    ~C_Test() override;
    void TickComponent(float delta_time) override;
};
