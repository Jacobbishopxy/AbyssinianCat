/**
 * @file:	Paw.hpp
 * @author:	Jacob Xie
 * @date:	2025/07/07 09:05:11 Monday
 * @brief:
 **/

#ifndef __Paw__H__
#define __Paw__H__

#include <atomic>

#include "AbyssinianCat/Cat.hpp"

class Paw : public Cat<Paw>
{
public:
    Paw(std::atomic<int>& energy);
    ~Paw();

    std::string_view actionYell() const;
    void actionPlay();
    void actionSleep();
    int actionEat(std::string& food);

private:
    std::atomic<int>& mEnergy;
};

#endif  //!__Paw__H__
