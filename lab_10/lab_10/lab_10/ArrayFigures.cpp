#include "ArrayFigures.h"

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

const std::string ellipse_name = { "Ellipse" };
const std::string shape_name = { "Shape" };
const std::string text_name = { "Text" };
const std::string rectangle_name = { "Rectangle" };
const std::string polygon_name = { "Polygon" };
const std::string star_name = { "Star" };

ArrayFigures::ArrayFigures()
{
    std::ifstream saves;
    saves.open("Saves.txt");
    if (saves.is_open()) {
        std::string line;
        while (getline(saves, line)) {
            std::vector<std::string> words = splitIntoWords(line);
            if (words.size() > 0) {
                size_t x = stoi(words.at(2));
                size_t y = stoi(words.at(4));
                const char* color = words.at(6).c_str();
                const std::string object_name = words.at(0);
                GraphObject* object;
                if (object_name == ellipse_name) {
                    size_t width = stoi(words.at(8));
                    size_t height = stoi(words.at(10));
                    object = new Ellipse(x, y, color, width, height);
                    add(object);
                }
                else if (words.at(0) == shape_name) {
                    size_t width = stoi(words.at(8));
                    size_t height = stoi(words.at(10));
                    object = new Shape(x, y, color, width, height);
                    add(object);
                }
                else if (words.at(0) == text_name) {
                    size_t font_size = stoi(words.at(8));
                    const char* text = words.at(10).c_str();
                    object = new Text(x, y, color, font_size, text);
                    add(object);
                }
                else if (words.at(0) == rectangle_name) {
                    size_t width = stoi(words.at(8));
                    size_t height = stoi(words.at(10));
                    object = new Rectangle(x, y, color, width, height);
                    add(object);
                }
                else if (words.at(0) == polygon_name) {
                    size_t width = stoi(words.at(8));
                    size_t height = stoi(words.at(10));
                    size_t vertex_count = stoi(words.at(10));
                    object = new Polygon(x, y, color, width, height, vertex_count);
                    add(object);
                }
                else if (words.at(0) == star_name) {
                    size_t width = stoi(words.at(8));
                    size_t height = stoi(words.at(10));
                    size_t vertex_count = stoi(words.at(10));
                    object = new Star(x, y, color, width, height, vertex_count);
                    add(object);
                }
            }
        }
        saves.close();
    }
    else {
        std::cout << "There are some problems with opening file\n";
    }
}

ArrayFigures::ArrayFigures(GraphObject* p_object) 
    : ArrayFigures()
{
    objects_.push_back(p_object);
}

ArrayFigures::ArrayFigures(const ArrayFigures& object) 
    : ArrayFigures()
{
    objects_ = object.objects_;
}

ArrayFigures::ArrayFigures(ArrayFigures&& object) noexcept
    : objects_(std::move(object.objects_))
{
}

ArrayFigures::~ArrayFigures()
{
    std::ofstream saves("Saves.txt");
    if (saves.is_open()) {
        size_t size = objects_.size();
        for (size_t i = 0; i < size; ++i) {
            saves << objects_.at(i);
        }
        saves.close();
    }
    objects_.erase(objects_.begin(), objects_.end());
}

void ArrayFigures::add(GraphObject* element)
{
    objects_.push_back(element);
}

void ArrayFigures::deleteElement(const size_t& count)
{
    objects_.erase(objects_.begin() + count);
}

size_t ArrayFigures::size()
{
    return objects_.size();
}

void ArrayFigures::print()
{
    size_t size = objects_.size();
    for (size_t i = 0; i < size; ++i) {
        GraphObject* obj = objects_.at(i);
        std::cout << obj << std::endl;
    }
}

std::vector<std::string> ArrayFigures::splitIntoWords(const std::string& text)
{
    std::string buf;                 // Have a buffer string
    std::stringstream ss(text);       // Insert the string into a stream
    std::vector<std::string> words; // Create vector to hold our words
    while (ss >> buf) {
        words.push_back(buf);
    }
    return words;
}