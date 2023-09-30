#pragma once
#include <iostream>

#include "GraphObject.h"
#include "Shape.h"
#include "Text.h"
#include "Ellipse.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Star.h"

class FigureList
{
    struct Node {
        GraphObject* data;
        Node* next;
        
        Node()
            : data(nullptr),
              next(nullptr)
        {}

        ~Node() {
            if (data) {
                delete data;
                data = nullptr;
            }
            if (next) {
                delete next;
                next = nullptr;
            }
        }
    } *head_;
    size_t size_;
public:
    /// <summary>
    /// constructor without any parameters
    /// </summary>
    FigureList();
    /// <summary>
    /// constructor that fills first element with some value
    /// </summary>
    /// <param name="number">this some value</param>
    FigureList(GraphObject* data);
    /// <summary>
    /// contructor coping
    /// </summary>
    /// <param name="rhs">object that is need to be copied</param>
    FigureList(const FigureList const& rhs);
    /// <summary>
    /// moving constructor
    /// </summary>
    /// <param name="rhs"></param>
    FigureList(FigureList && rhs);
    // destructor
    virtual ~FigureList();
    /// <summary>
    /// Given a reference (pointer to pointer)
    /// to the head of a listand an int, inserts
    /// a new node on the front of the list.
    /// </summary>
    /// <param name="head_ref"></param>
    /// <param name="new_data"></param>
    virtual void prepend(GraphObject* new_data);
    /// <summary>
    /// Given a node prev_node, insert a new node after the given
    /// prev_node
    /// </summary>
    /// <param name="prev_node">pointer to item after should element be</param>
    /// <param name="new_data">data that is need to be inserted</param>
    virtual void insertAfter(const size_t& prev_element, GraphObject* new_data);
    /// <summary>
    /// Given a reference (pointer to pointer) to the head
    /// of a list and an int, appends a new node at the end
    /// </summary>
    /// <param name="head_ref">pointer to pointer of element</param>
    /// <param name="new_data">data that should be after</param>
    virtual void append(GraphObject* new_data);
    /// <summary>
    /// This function prints contents of 
    /// linked list starting from head  
    /// </summary>
    virtual void print();
    /// <summary>
    /// remove first element
    /// </summary>
    virtual void removeFirst();
    /// <summary>
    /// remove choosen element
    /// </summary>
    /// <param name="position">number of element throught start</param>
    virtual void removeAt(const size_t& position);
    /// <summary>
    /// remove all elements
    /// </summary>
    virtual void removeAll();
    /// <returns>size of this list</returns>
    virtual size_t size();
    /// <summary>
    /// overload copy operator
    /// </summary>
    /// <param name="object">object that is need to be copied</param>
    /// <returns>referrence to class of simmilar objects</returns>
    FigureList& operator=(const FigureList& object);
    /// <summary>
    /// move operator overload
    /// </summary>
    /// <param name="object">object that is need to be moved</param>
    /// <returns>refference to class of this object</returns>
    FigureList& operator=(FigureList&& object);
private:
    /// <summary>
    /// function that gets data from position of this element, that is bases on counter steps to aim
    /// </summary>
    /// <param name="counter">unsigned int, counter steps to goal</param>
    /// <returns>data that is situated in node that going this steps</returns>
    virtual Node* get(const size_t& counter);
    /// <summary>
    /// function that is used to in full get function
    /// </summary>
    /// <param name="node">pointer to Node structure</param>
    /// <param name="counter">steps that this function should follow</param>
    /// <returns>data that is situated in node that going this steps</returns>
    Node* get(Node* node, const size_t& counter);
    /// <summary>
    /// function to copy one node in this list
    /// </summary>
    /// <param name="node">which information we try to copy</param>
    void copy(Node* node);
};