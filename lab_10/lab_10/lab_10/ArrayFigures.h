#pragma once
#include "GraphObject.h"
#include "Shape.h"
#include "Text.h"
#include "Ellipse.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Star.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class ArrayFigures {
    std::vector<GraphObject*> objects_;
public:
    /// <summary>
    /// constructor without any parameters
    /// </summary>
    ArrayFigures();
    /// <summary>
    /// constructor with adding new object
    /// </summary>
    /// <param name="element"></param>
    ArrayFigures(GraphObject* element);
    /// <summary>
    /// constructor of copying
    /// </summary>
    /// <param name="p_object"></param>
    ArrayFigures(const ArrayFigures& p_object);
    /// <summary>
    /// constructor with moving elements
    /// </summary>
    /// <param name="object">object that is need to be moved</param>
    ArrayFigures(ArrayFigures&& object) noexcept;
    /// <summary>
    /// virtual distructor with saving data after closing program 
    /// </summary>
    virtual ~ArrayFigures();
    /// <summary>
    /// adding a new element t oa program
    /// </summary>
    /// <param name="element">pointer to base object class</param>
    virtual void add(GraphObject* element);
    /// <summary>
    /// delete single element
    /// </summary>
    /// <param name="count"></param>
    virtual void deleteElement(const size_t& count);
    /// <summary>
    /// function to know the size of object
    /// </summary>
    /// <returns></returns>
    virtual size_t size();
    /// <summary>
    /// function to print all the data
    /// </summary>
    virtual void print();
private:
    /// <summary>
    /// function that divides string into words
    /// </summary>
    /// <param name="text">line that consists of multiple words</param>
    /// <returns>vector array of strings</returns>
    std::vector <std::string> splitIntoWords(const std::string& text);
};

