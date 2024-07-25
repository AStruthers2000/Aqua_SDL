#pragma once
#include "Actor/Actor.h"

class ATest : public AquaEngine::Actor
{
public:
    explicit ATest(AquaEngine::GameState* game_state)
        : Actor(game_state)
    {
        test = (int*)malloc(sizeof(int) * 1000000);
        for(int i = 0; i < 1000000; i++)
        {
            test[i] = i + 1000000;
        }
    }

    ~ATest() override;
    void BeginPlay() override;
    void TickActor(float delta_time) override;

private:
    int* test;
};
