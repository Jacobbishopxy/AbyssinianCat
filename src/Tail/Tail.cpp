/**
 * @file:	Tail.cpp
 * @author:	Jacob Xie
 * @date:	2025/07/08 14:07:43 Tuesday
 * @brief:
 **/

#include "AbyssinianCat/Tail.hpp"

#include <iostream>

TailImpl::TailImpl()
{
}

TailImpl::~TailImpl()
{
}

std::string_view TailImpl::yell() const
{
    return "The cat stands its tail.";
}

void TailImpl::play()
{
    std::cout << "The cat shakes its tail." << std::endl;
}

void TailImpl::sleep()
{
    std::cout << "The cat curls up its tail." << std::endl;
}

int TailImpl::eat(std::string& food)
{
    std::cout << "The cat hangs down its tail." << std::endl;
    return 0;
}
