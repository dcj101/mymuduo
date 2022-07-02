#pragma once
/**
 * @brief 
 * @copyright dcj 
 *  noncopyable 这里是禁止了拷贝构造和赋值语句,但是构造函数设置成了protected模式
 *  继承的类可以构造
 * 
 */
class noncopyable
{
public:
    noncopyable(const noncopyable&) = delete;
    noncopyable & operator=(const noncopyable&) = delete;
protected:
    noncopyable()=default;
    ~noncopyable()=default;
};
