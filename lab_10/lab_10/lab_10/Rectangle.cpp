#include "Rectangle.h"

Rectangle::Rectangle() : Shape()
{
}

Rectangle::Rectangle(const size_t& x, const size_t& y, const char* color, const size_t& width, const size_t& height)
    : Shape(x, y, color, width, height)
{
}

Rectangle::Rectangle(const Rectangle& rhs)
    : Shape(rhs.x_, rhs.y_, rhs.color_, rhs.width_, rhs.height_)
{
}

char* Rectangle::print() const
{
    char* message = new char[max_text_length];
    sprintf_s(message, max_text_length, "Rectangle x= %u y= %u color= %s width= %u height= %u ", x_, y_, color_, width_, height_);
    return message;
}