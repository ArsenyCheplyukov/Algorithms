#pragma once
#include "Shape.h"

class Ellipse : public Shape
{
private:
    /// <summary>
    /// redefinition of function print
    /// </summary>
    virtual char* print() const override;
public:
    /// <summary>
    /// construcor without any parameters
    /// </summary>
    Ellipse();
    /// <summary>
    /// constructor with all the parameters 
    /// </summary>
    /// <param name="x">count of object size in x axis</param>
    /// <param name="y">count of object size in y axis</param>
    /// <param name="color">c-styled array of chars that is object's color</param>
    /// <param name="width">object's size in width</param>
    /// <param name="height">object's size in height</param>
    Ellipse(const size_t& x, const size_t& y, const char* color, const size_t& width, const size_t& height);
    /// <summary>
    /// constructor with copying
    /// </summary>
    /// <param name="rhs">object that is need to be copyied</param>
    Ellipse(const Ellipse& rhs);
    /// <summary>
    /// virtual destructor
    /// </summary>
    virtual ~Ellipse() = default;
    //"Ellipse"
    //byte * serialize() {};
};