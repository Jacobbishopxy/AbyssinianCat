/**
 * @file:	test_paw.cpp
 * @author:	Jacob Xie
 * @date:	2025/07/08 16:41:13 Tuesday
 * @brief:
 **/

#include <AbyssinianCat/Paw.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    std::atomic<int> e{55};
    Paw p(e);

    auto y = p.yell();
    std::cout << "Yell: " << y << std::endl;
    p.play();
    p.sleep();
    std::string food = "fish";
    auto res = p.eat(food);
    std::cout << "Ate left: " << res << std::endl;

    return 0;
}
