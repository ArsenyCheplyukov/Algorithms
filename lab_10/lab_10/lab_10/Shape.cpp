#include "Shape.h"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

Shape::Shape()
    : GraphObject(),
    width_(0),
    height_(0)
{
}

Shape::Shape(const size_t& width, const size_t& height)
    : GraphObject()
{
    if ((max_object_width >= width) && (max_width >= width + x_)) {
        width_ = width;
    }
    else {
        width_ = max_object_width - x_;
    }
    if ((max_object_height >= height) && (max_height >= height + y_)) {
        height_ = height;
    }
    else {
        height_ = max_object_height - y_;
    }
}

Shape::Shape(const size_t& x, const size_t& y, const char* color,
    const size_t& width, const size_t& height)
    : GraphObject(x, y, color)
{
    if ((max_object_width >= width) && (max_width >= width + x_)) {
        width_ = width;
    }
    else {
        width_ = max_object_width - x_;
    }
    if ((max_object_height >= height) && (max_height >= height + y_)) {
        height_ = height;
    }
    else {
        height_ = max_object_height - y_;
    }
}

Shape::Shape(const Shape& rhs) 
    : GraphObject(rhs.x_, rhs.y_, rhs.color_),
width_(rhs.width_), height_(rhs.height_)
{
}

size_t Shape::getWidth() const
{
    return width_;
}

void Shape::setWidth(const size_t& width)
{
    if ((max_object_width >= width) && (max_width >= width + x_)) {
        width_ = width;
    }
}

size_t Shape::getHeight() const
{
    return height_;
}

void Shape::setHeight(const size_t& height)
{
    if ((max_object_height >= height) && (max_height >= height + y_)) {
        height_ = height;
    }
    else {
        height_ = height - y_;
    }
}

char* Shape::print() const
{
    char* message = new char[max_text_length];
    sprintf_s(message, max_text_length, "Shape x= %u y= %u color= %s width= %u height= %u ", x_, y_, color_, width_, height_);
    return message;
}
