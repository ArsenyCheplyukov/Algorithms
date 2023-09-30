#pragma once
#include "GraphObject.h"

const size_t max_font_size = 128;

class Text : public GraphObject
{
    char* text_ = new char[max_text_length];
    size_t font_size_;
    /// <summary>
    /// print all information and name of this object
    /// </summary>
    virtual char* print() const override;
public:
    /// <summary>
    /// constructor without any parameters
    /// </summary>
    Text();
    /// <summary>
    /// constructor in which we don't need to know width and height of text 
    /// </summary>
    /// <param name="x">size_t axis of x</param>
    /// <param name="y">size_t axis of y</param>
    /// <param name="color">array of chars that make name of color</param>
    /// <param name="font_size">size_t type of text size</param>
    /// <param name="text">array of chars that make name of text</param>
    Text(const size_t& x, const size_t& y, const char* color, const size_t& font_size, const char* text);
    /// <summary>
    /// constructor of copying
    /// </summary>
    /// <param name="rhs">object that is need to be copyied</param>
    Text(const Text& rhs);
    /// <summary>
    /// virtual destructor
    /// </summary>
    virtual ~Text();
    /// <summary>
    /// setter for text
    /// </summary>
    virtual void setText(const char* text);
    /// <summary>
    /// setter for font size
    /// </summary>
    virtual void setFontSize(const size_t& font_size);
    /// <summary>
    /// getter for text
    /// </summary>
    /// <returns>constant c-style array of text</returns>
    virtual char* getText() const;
    /// <summary>
    /// getter for font size
    /// </summary>
    /// <returns>constant amount of font size</returns>
    virtual size_t getFontSize() const;
    //byte* serialize() {};
};