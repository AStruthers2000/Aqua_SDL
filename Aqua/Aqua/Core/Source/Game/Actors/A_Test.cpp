#include "A_Test.h"

#include <iostream>

A_Test::~A_Test()
{
    std::cout << "Goodbye actor" << std::endl;
    delete[] test;
}

void A_Test::TickActor(float delta_time)
{
    std::cout << "I am an actor and i am ticking" << std::endl;
}


