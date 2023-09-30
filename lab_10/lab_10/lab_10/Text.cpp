#include "Text.h"

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

Text::Text()
    : GraphObject(),
    text_(0), font_size_(0)
{
}

Text::Text(const size_t& x, const size_t& y, const char* color, const size_t& font_size, const char* text)
    : GraphObject(x, y, color)
{
    size_t size = strlen(text);
    if (font_size <= max_font_size) {
        font_size_ = font_size;
    }
    else {
        font_size_ = 0;
    }
    if (max_text_length >= size) {
        memcpy(text_, text, size + 1);
    }
    else {
        text_[0] = '\0';
    }
}

Text::Text(const Text& rhs)
    : GraphObject(rhs.x_, rhs.y_, rhs.color_),
    text_(rhs.text_), font_size_(rhs.font_size_)
{
}

Text::~Text()
{
    if (text_) {
        delete[] text_;
        text_ = nullptr;
    }
}

void Text::setText(const char* text)
{
    size_t size = strlen(text);
    if (size <= max_text_length) {
        memcpy(text_, text, size);
    }
    else {
        memcpy(text_, "\0", 1);
    }
}

void Text::setFontSize(const size_t& font_size)
{
    if (font_size != font_size && font_size <= max_font_size) {
        font_size_ = font_size;
    }
}

char* Text::getText() const
{
    return text_;
}

size_t Text::getFontSize() const
{
    return font_size_;
}

char* Text::print() const
{
    char* message = new char[max_text_length];
    sprintf_s(message, max_text_length, "Text x= %u y= %u color= %s font_size= %u text= %s ", x_, y_, color_, font_size_, text_);
    return message;
}
