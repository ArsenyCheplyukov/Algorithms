#include "Star.h"
#include <sstream>

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

Star::Star()
    : Shape(), vertex_count_(0)
{
}

Star::Star(const size_t& vertex_count) : Shape()
{
    if (vertex_count <= max_vertex_count) {
        vertex_count_ = vertex_count;
    }
    else {
        vertex_count_ = max_vertex_count;
    }
}

Star::Star(const size_t& x, const size_t& y, const char* color, const size_t& width, const size_t& height, const size_t& vertex_count)
    : Shape(x, y, color, width, height)
{
    if (vertex_count <= max_vertex_count) {
        vertex_count_ = vertex_count;
    }
    else {
        vertex_count_ = max_vertex_count;
    }
}

Star::Star(const Star& rhs)
    : Shape(rhs.x_, rhs.y_, rhs.color_, rhs.width_, rhs.height_),
    vertex_count_(rhs.vertex_count_)
{
}

void Star::setVertexCount(const size_t& vertex_count)
{
    if (vertex_count <= max_vertex_count) {
        vertex_count_ = vertex_count;
    }
    else {
        vertex_count_ = max_vertex_count;
    }
}

size_t Star::getVertexCount() const
{
    return vertex_count_;
}

char* Star::print() const
{
    //std::stringstream ss;
    //ss << "Start x= " << x << " y= " << y; ....
    //return ss.str().c_str();
    char* message = new char[max_text_length];
    sprintf_s(message, max_text_length, "Star x= %u y= %u color= %s width= %u height= %u vertex= %u ", x_, y_, color_, width_, height_, vertex_count_);
    return message;
}
