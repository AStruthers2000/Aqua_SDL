#include "ATest.h"

#include <iostream>

#include "../Components/CTest.h"
#include "Component/Rendering/CSquareRenderer.h"

ATest::~ATest()
{
    std::cout << "Goodbye actor" << std::endl;
    delete[] test;
}

void ATest::BeginPlay()
{
    std::cout << "Beginning test actor" << std::endl;
    AddComponent(std::make_shared<CTest>(this, 10));
    AddComponent(std::make_shared<CTest>(this, 100));
    AddComponent(std::make_shared<CTest>(this, 9));
    AddComponent(std::make_shared<AquaEngine::CSquareRenderer>(
        this,
        1,
        AquaColor{100, 100, 255, 255},
        AquaEngine::Vector2{50, 50},
        AquaEngine::Vector2{100, 100}));
}

void ATest::TickActor(float delta_time)
{
    //std::cout << "I am an actor and i am ticking" << std::endl;
    const float speed { 100.f };
    const AquaEngine::Vector2<float> delta_position = speed * delta_time;
    std::cout << "delta position: (" << delta_position.x << ", " << delta_position.y << ")" << std::endl;
    SetActorPosition(GetActorPosition() + delta_position);
}


