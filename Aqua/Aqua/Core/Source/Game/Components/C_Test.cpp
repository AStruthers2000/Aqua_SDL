#include "C_Test.h"
#include <iostream>

C_Test::~C_Test()
{
    std::cout << "Deleting test component from actor" << std::endl;
}

void C_Test::TickComponent(float delta_time)
{
    //Component::TickComponent(delta_time);
    //std::cout << "Updating component with order " << GetUpdateOrder() << std::endl;
    
}
