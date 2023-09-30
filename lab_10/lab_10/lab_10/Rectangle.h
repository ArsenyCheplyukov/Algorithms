#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
    /// <summary>
    /// redefined function of print
    /// </summary>
    virtual char* print() const override;
public:
    /// <summary>
    /// constructor without any parameters
    /// </summary>
    Rectangle();
    /// <summary>
    /// constructor with all variables
    /// </summary>
    Rectangle(const size_t& x, const size_t& y, const char* color, const size_t& width, const size_t& height);
    /// <summary>
    /// constructor of copying
    /// </summary>
    Rectangle(const Rectangle& rhs);
    /// <summary>
    /// virtual destructor
    /// </summary>
    virtual ~Rectangle() = default;
    //byte* serialize() {};
};