#pragma once
#include "Shape.h"

class Star : public Shape
{
    size_t vertex_count_;
    /// <summary>
    /// override of print function
    /// </summary>
    virtual char* print() const override;
public:
    /// <summary>
    /// constructor without any parameters
    /// </summary>
    Star();
    /// <summary>
    /// constructor with one parameter new from shape
    /// </summary>
    /// <param name="vertex_count">number of convex angles (size_t)</param>
    Star(const size_t& vertex_count);
    /// <summary>
    /// constructor with all the parameters
    /// </summary>
    /// <param name="x">start position in x axis</param>
    /// <param name="y">start position in y axis</param>
    /// <param name="color">name of color (c-style string (array of characters))</param>
    /// <param name="width">width size of object</param>
    /// <param name="height">height size of object</param>
    /// <param name="vertex_count">number of convex angles (size_t)</param>
    Star(const size_t& x, const size_t& y, const char* color, const size_t& width, const size_t& height, const size_t& vertex_count);
    /// <summary>
    /// constructor copying
    /// </summary>
    /// <param name="rhs">object that is need to be copied</param>
    Star(const Star& rhs);
    /// <summary>
    /// virtual destructor
    /// </summary>
    virtual ~Star() = default;
    /// <summary>
    /// setter for vertex counter
    /// </summary>
    /// <param name="vertex_count">number of convex angles (size_t)</param>
    virtual void setVertexCount(const size_t& vertex_count);
    /// <summary>
    /// getter for vertex counter
    /// </summary>
    /// <returns>number of convex angles (size_t)</returns>
    virtual size_t getVertexCount() const;
    //byte* serialize() {};
};