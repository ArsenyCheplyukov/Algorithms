#include "FigureList.h"

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

FigureList::FigureList()
    : head_(nullptr), size_(0)
{
}

FigureList::FigureList(GraphObject* data)
{
    if (data) {
        head_ = new Node();
        head_->data = data;
        ++size_;
    }
}

FigureList::FigureList(const FigureList const& rhs)
{
    head_ = new Node();
    size_ = rhs.size_;
    if (head_ != nullptr) {
        copy(rhs.head_);
    }
}

FigureList::FigureList(FigureList&& rhs)
    : head_(std::move(rhs.head_)), size_(rhs.size_)
{
}

FigureList::~FigureList()
{
    removeAll();
}

void FigureList::prepend(GraphObject* new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
    /* 2. put in the data */
    new_node->data = new_data;
    /* 3. Make next of new node as head */
    new_node->next = head_;
    /* 4. move the head to point to the new node */
    head_ = new_node;
    ++size_;
}

void FigureList::insertAfter(const size_t& prev_element, GraphObject* new_data)
{
    Node* prev_node = get(prev_element);
    /*1. check if the given prev_node is NULL */
    if (prev_node == nullptr) {
        return;
    }
    /* 2. allocate new node */
    Node* new_node = new Node();
    /* 3. put in the data */
    new_node->data = new_data;
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
    size_++;
}

void FigureList::append(GraphObject* new_data)
{
    /* 1. allocate node */
    ++size_;
    Node* new_node = new Node();
    /* used in step 5*/
    Node* last = head_;
    /* 2. put in the data */
    new_node->data = new_data;
    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    delete new_node->next;
    new_node->next = nullptr;
    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (head_ == nullptr) {
        head_ = new_node;
        return;
    }
    /* 5. Else traverse till the last node */
    while (last->next != nullptr) {
        last = last->next;
    }
    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

void FigureList::print()
{
    const Node* ptr = head_;
    while (ptr && ptr->data) {
        std::cout << ptr->data << std::endl;
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

void FigureList::removeFirst()
{
    if (head_ && head_->next) {
        Node* head_node = head_;
        Node* next_node = head_->next;
        head_node->next = nullptr;
        delete head_node;
        head_ = next_node;
        --size_;
    }
}

void FigureList::removeAt(const size_t& position)
{
    if (position > size_) {
        return;
    }
    Node* current = head_->next;
    for (int i = 1; current != nullptr && i < (position - 1); ++i) {
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr) {
        return;
    }
    Node* temp = current->next;
    current->next = temp->next;
    temp->next = nullptr;
    delete temp;
    temp = nullptr;
    --size_;
}

void FigureList::removeAll()
{
    delete head_;
    head_ = nullptr;
    size_ = 0;
}

FigureList::Node* FigureList::get(const size_t& counter)
{
    if (counter != 0) {
        get(head_->next, (counter - 1));
    }
    else {
        return head_;
    }
}

FigureList::Node* FigureList::get(Node* node, const size_t& counter)
{
    if (counter < size_) {
        if (counter != 0) {
            get(node->next, (counter - 1));
        }
        else {
            return node;
        }
    }
    else {
        return nullptr;
    }
}

size_t FigureList::size()
{
    return size_;
}

FigureList& FigureList::operator=(const FigureList& object)
{
    if (this != &object) {
        size_ = object.size_;
        Node* current = head_;
        Node* object_current = object.head_;
        for (size_t i = 0; i < size_; ++i) {
            delete current->data;
            head_->data = nullptr;
            current->data = object_current->data;
            if (head_->next == nullptr) {
                current->next = new Node();
            }
            current = current->next;
            object_current = object_current->next;
        }
    }
    return *this;
}

FigureList& FigureList::operator=(FigureList&& object)
{
    if (this != &object) {
        size_ = object.size_;
        Node* current = head_;
        Node* object_current = object.head_;
        for (size_t i = 0; i < size_; ++i) {
            delete current->data;
            head_->data = nullptr;
            current->data = object_current->data;
            if (head_->next == nullptr) {
                current->next = new Node();
            }
            current->data = std::move(object_current->data);
            current = current->next;
            object_current = object_current->next;
        }
    }
    return *this;
}

void FigureList::copy(Node* node)
{
    if (node) {
        if (node->next != nullptr) {
            head_->next = node->next;
            head_->data = node->data;
            copy(node->next);
        }
    }
}