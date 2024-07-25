#include "A_Test.h"

#include <iostream>

#include "../Components/C_Test.h"
#include "Component/C_SquareRender.h"

A_Test::~A_Test()
{
    std::cout << "Goodbye actor" << std::endl;
    delete[] test;
}

void A_Test::BeginPlay()
{
    std::cout << "Beginning test actor" << std::endl;
    AddComponent(new C_Test(this, 10));
    AddComponent(new C_Test(this, 100));
    AddComponent(new C_Test(this, 9));
    AddComponent(new AquaEngine::C_SquareRender(this, 1, {100, 100, 255, 255}, {50, 50}, {100, 100}));
}

void A_Test::TickActor(float delta_time)
{
    //std::cout << "I am an actor and i am ticking" << std::endl;
    const float speed { 100.f };
    const AquaEngine::Vector2<float> delta_position = speed * delta_time;
    std::cout << "delta position: (" << delta_position.x << ", " << delta_position.y << ")" << std::endl;
    SetActorPosition(GetActorPosition() + delta_position);
}


