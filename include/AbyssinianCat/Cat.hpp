/**
 * @file:	Cat.hpp
 * @author:	Jacob Xie
 * @date:	2025/07/06 23:38:29 Sunday
 * @brief:
 **/

#ifndef __CAT__H__
#define __CAT__H__

#include <string_view>

template <typename Drv>
class Cat
{
public:
    std::string_view yell() const
    {
        return static_cast<const Drv*>(this)->actionYell();
    }

    void play()
    {
        static_cast<Drv*>(this)->actionPlay();
    }

    void sleep()
    {
        static_cast<Drv*>(this)->actionSleep();
    }

    int eat(std::string& food)
    {
        return static_cast<Drv*>(this)->actionEat(food);
    }
};

#endif  //!__CAT__H__
