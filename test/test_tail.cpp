/**
 * @file:	test_tail.cpp
 * @author:	Jacob Xie
 * @date:	2025/07/08 15:19:29 Tuesday
 * @brief:
 **/

#include <AbyssinianCat/Tail.hpp>
#include <iostream>

class MyShape
{
public:
    std::string_view description() const
    {
        return "Biggie vibes!";
    }

    int size() const
    {
        return 100;
    }

    bool empty() const
    {
        return false;
    }
};

int main(int argc, char** argv)
{
    MyShape s;
    Tail<MyShape> t(std::move(s));

    auto y = t.yell();
    std::cout << "Yell: " << y << std::endl;
    t.play();
    t.sleep();
    std::string food = "fish";
    auto res = t.eat(food);
    std::cout << "Ate left: " << res << std::endl;

    return 0;
}
