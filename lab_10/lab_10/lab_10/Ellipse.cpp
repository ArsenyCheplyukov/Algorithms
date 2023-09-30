#include "Ellipse.h"

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

Ellipse::Ellipse(const size_t& x, const size_t& y, const char* color, const size_t& width, const size_t& height)
    : Shape(x, y, color, width, height)
{
}

Ellipse::Ellipse() : Shape()
{
}

Ellipse::Ellipse(const Ellipse& rhs)
    : Shape(rhs.x_, rhs.y_, rhs.color_, rhs.width_, rhs.height_)
{
}

char* Ellipse::print() const
{
    char* message = new char[max_text_length];
    sprintf_s(message, max_text_length, "Ellipse x= %i y= %i color= %s width= %i height= %i ", x_, y_, color_, width_, height_);
    return message;
}