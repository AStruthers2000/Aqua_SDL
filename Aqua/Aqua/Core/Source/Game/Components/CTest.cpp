#include "CTest.h"
#include <iostream>

CTest::~CTest()
{
    std::cout << "Deleting test component from actor" << std::endl;
}

void CTest::TickComponent(float delta_time)
{
    //Component::TickComponent(delta_time);
    //std::cout << "Updating component with order " << GetUpdateOrder() << std::endl;
    
}
