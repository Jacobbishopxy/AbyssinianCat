/**
 * @file:	Tail.hpp
 * @author:	Jacob Xie
 * @date:	2025/07/08 13:12:20 Tuesday
 * @brief:
 **/

#ifndef __TAIL__H__
#define __TAIL__H__

#include <memory>

#include "AbyssinianCat/Cat.hpp"

// clang-format off
template <typename T>
concept Sizable = requires(const T& obj) {
    // std::string_view description()
    { obj.description() } -> std::same_as<std::string_view>;
    // int size()
    { obj.size() } -> std::integral;
    // bool empty()
    { obj.empty() } -> std::same_as<bool>;
};

// clang-format on

class TailImpl
{
public:
    TailImpl();
    ~TailImpl();

    std::string_view yell() const;
    void play();
    void sleep();
    int eat(std::string& food);
};

template <Sizable T>
class Tail : public Cat<Tail<T>>
{
public:
    Tail(T&& shape)
        : mShape(std::forward<T>(shape)) {}

    ~Tail() = default;

    std::string_view actionYell() const
    {
        return this->mTailImpl->yell();
    }

    void actionPlay()
    {
        this->mTailImpl->play();
    }

    void actionSleep()
    {
        this->mTailImpl->sleep();
    }

    int actionEat(std::string& food)
    {
        return this->mTailImpl->eat(food);
    }

    const T& getShape() const
    {
        return mShape;
    }

private:
    T mShape;

    std::unique_ptr<TailImpl> mTailImpl;
};

#endif  //!__TAIL__H__
