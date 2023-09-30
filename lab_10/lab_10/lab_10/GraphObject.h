#pragma once
#include <iostream>
#include <string>
#include <cstring>  //For the string functions

const size_t max_width = 1080;
const size_t max_height = 720;
const size_t max_object_width  = 1000;
const size_t max_object_height = 700;
const size_t max_text_length   = 128;
const size_t max_vertex_count = 360;

class GraphObject
{
    /// <summary>
    /// virtual print method
    /// </summary>
    virtual char* print() const = 0;
protected:
    size_t x_, y_;
    char* color_ = new char[max_text_length];
public:
    /// <summary>
    /// costructor, without any parameters
    /// </summary>
    GraphObject();
    /// <summary>
    /// constructor with all of the parameters of color and axis coordinates
    /// </summary>
    /// <param name="x">coordinates of x axis</param>
    /// <param name="y">coordinates of y axis</param>
    /// <param name="color">name of color in c-style</param>
    GraphObject(const size_t& x, const size_t& y, const char* color);
    /// <summary>
    /// constructor with copying
    /// </summary>
    GraphObject(const GraphObject& obj);
    /// <summary>
    /// virtual destructor for son's classes succesfully destruction
    /// </summary>
    virtual ~GraphObject() = 0;
    /// <summary>
    /// getter for x
    /// </summary>
    /// <returns>double value of x </returns>
    virtual double getX() const;
    /// <summary>
    /// setter for x
    /// </summary>
    virtual void setX(const size_t& x);
    /// <summary>
    /// getter for y
    /// </summary>
    /// <returns>double value of y</returns>
    virtual double getY() const;
    /// <summary>
    /// setter for y 
    /// </summary>
    virtual void setY(const size_t& y);
    /// <summary>
    /// getter for color 
    /// </summary>
    /// <returns>c-style name of color</returns>
    virtual char* getColor() const;
    /// <summary>
    /// setter for color
    /// </summary>
    /// <param name="color">c-style name of color</param>
    virtual void setColor(const char* color);
    /// <summary>
    /// overload of output operator
    /// </summary>
    friend std::ostream& operator<< (std::ostream& out, const GraphObject* rhs);
    //virtual byte* serialize() = 0;
    //virtual GraphObject* deserialize() = 0;
};

