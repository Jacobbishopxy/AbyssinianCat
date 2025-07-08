/**
 * @file:	Paw.cpp
 * @author:	Jacob Xie
 * @date:	2025/07/06 23:24:52 Sunday
 * @brief:
 **/

#include "AbyssinianCat/Paw.hpp"

#include <iostream>

const std::string_view REJECT = "A slow, deliberate paw wave signals 'no thanks'.";

Paw::Paw(std::atomic<int>& energy)
    : mEnergy(energy) {}

Paw::~Paw() = default;

std::string_view Paw::actionYell() const
{
    return "The cat shines its claws.";
}

void Paw::actionPlay()
{
    if (mEnergy.load() > 50)
    {
        std::cout << "The cat sheathes its claws." << std::endl;
        mEnergy.fetch_sub(5);
    }
    else
        std::cout << REJECT << std::endl;
}

void Paw::actionSleep()
{
    if (mEnergy.load() > 40)
        std::cout << REJECT << std::endl;
    else
    {
        std::cout << "The paw pads are plush yet resilient." << std::endl;
        mEnergy.fetch_add(20);
    }
}

int Paw::actionEat(std::string& food)
{
    if (mEnergy.load() > 70)
        std::cout << REJECT << std::endl;
    else
    {
        std::cout << "The tension leaves the cat's paws." << std::endl;
        mEnergy.fetch_add(30);
    }

    return mEnergy.load();
}
