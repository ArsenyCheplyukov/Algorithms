#include "GraphObject.h"

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

GraphObject::GraphObject()
{
    x_ = 0; y_ = 0;
    const char* word = "transparent";
    memcpy(color_, word, strlen(word) + 1);
}

GraphObject::GraphObject(const size_t& x, const size_t& y, const char* color)
{
    size_t word_size = strlen(color);
    if (x <= max_width) {
        x_ = x;
    }
    else {
        x_ = 0;
    }
    if (y <= max_height) {
        y_ = y;
    }
    else {
        y_ = 0;
    }
    if (word_size <= max_text_length) {
        memcpy(color_, color, strlen(color) + 1);
    }
    else {
        const char* word = "transparent\0";
        memcpy(color_, word, strlen(word) + 1);
    }
}

GraphObject::GraphObject(const GraphObject& obj)
{
    x_ = obj.x_; y_ = obj.y_;
    memcpy(color_, obj.color_, strlen(obj.color_) + 1);
}

GraphObject::~GraphObject()
{
    if (color_) {
        delete[] color_;
        color_ = nullptr;
    }
}

double GraphObject::getX() const
{
    return x_;
}

void GraphObject::setX(const size_t& x)
{
    if (x <= max_width) {
        x_ = x;
    }
}

double GraphObject::getY() const
{
    return y_;
}

void GraphObject::setY(const size_t& y)
{
    if (y <= max_height) {
        y_ = y;
    }
}

char* GraphObject::getColor() const
{
    return color_;
}

void GraphObject::setColor(const char* color)
{
    size_t size = strlen(color);
    if (size <= max_text_length) {
        memcpy(color_, color, size);
    }
    else {
        const char* word = "transparent";
        memcpy(color_, word, strlen(word) + 1);
    }
}

std::ostream& operator<< (std::ostream& out, const GraphObject* rhs)
{
    char* message = rhs->print();
    if (message) {
        out << message << std::endl;
        // Deallocate memory for message
        delete message;
        message = nullptr;
    }
    return out;
}