#pragma once
#include "GraphObject.h"

class Shape : public GraphObject
{
    /// <summary>
    /// prints name and all data parameters 
    /// </summary>
    virtual char* print() const override;
protected:
    size_t width_;
    size_t height_;
public:
    /// <summary>
    /// constructor without any parameters
    /// </summary>
    Shape();
    /// <summary>
    /// constructor with width and height parameters of figure
    /// </summary>
    /// <param name="width">max width of figure</param>
    /// <param name="height">max height parameter of figure</param>
    Shape(const size_t& width, const size_t& height);
    /// <summary>
    /// constructor with all of the parameters that shape should have
    /// </summary>
    /// <param name="x">(x - axis) - size_t</param>
    /// <param name="y">(y - axis) - size_t</param>
    /// <param name="color">color - array of chars</param>
    /// <param name="width">width - size_t</param>
    /// <param name="height">height - size_t</param>
    Shape(const size_t& x, const size_t& y, const char* color, const size_t& width, const size_t& height);
    /// <summary>
    /// constructor with copying
    /// </summary>
    /// <param name="rhs">rhs that is need to be copyied</param>
    Shape(const Shape& rhs);
    /// <summary>
    /// virtual destructor
    /// </summary>
    virtual ~Shape() = default;
    /// <summary>
    /// function to get width
    /// </summary>
    /// <returns>size_t of width</returns>
    virtual size_t getWidth() const;
    /// <summary>
    /// function to set width
    /// </summary>
    /// <param name="width">amount of height</param>
    virtual void setWidth(const size_t& width);
    /// <summary>
    /// function of getting height
    /// </summary>
    /// <returns>size_t of figure height</returns>
    virtual size_t getHeight() const;
    /// <summary>
    /// function to set height
    /// </summary>
    /// <param name="width">amount of width</param>
    virtual void setHeight(const size_t& width);
    //byte* serialize() {};
};