#pragma once
#include "Actor/Actor.h"

class A_Test : public AquaEngine::Actor
{
public:
    explicit A_Test(AquaEngine::GameState* game_state)
        : Actor(game_state)
    {
        test = (int*)malloc(sizeof(int) * 1000000);
        for(int i = 0; i < 1000000; i++)
        {
            test[i] = i + 1000000;
        }
    }

    ~A_Test() override;
    void TickActor(float delta_time) override;

private:
    int* test;
};
