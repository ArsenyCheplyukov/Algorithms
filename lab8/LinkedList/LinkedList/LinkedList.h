#pragma once
#include <iostream> 

// A linked list node  
template<typename T>
class LinkedList
{
    struct Node {
        T data;
        Node* next;
        ~Node() {
            delete next;
            next = nullptr;
        }
    } *head_;
    size_t size_;
public:
    /// <summary>
    /// constructor without any parameters
    /// </summary>
    LinkedList();
    /// <summary>
    /// constructor that fills first element with some value
    /// </summary>
    /// <param name="number">this some value</param>
    LinkedList(const T& data);
    /// <summary>
    /// contructor coping
    /// </summary>
    /// <param name="rhs">object that is need to be copied</param>
    LinkedList(const LinkedList& rhs);
    // destructor
    virtual ~LinkedList();
    /// <summary>
    /// Given a reference (pointer to pointer)
    /// to the head of a listand an int, inserts
    /// a new node on the front of the list.
    /// </summary>
    /// <param name="head_ref"></param>
    /// <param name="new_data"></param>
    void prepend(const T& new_data);
    /// <summary>
    /// Given a node prev_node, insert a new node after the given
    /// prev_node
    /// </summary>
    /// <param name="prev_node">pointer to item after should element be</param>
    /// <param name="new_data">data that is need to be inserted</param>
    void insertAfter(const Node*& prev_node, const T& new_data);
    /// <summary>
    /// Given a reference (pointer to pointer) to the head
    /// of a list and an int, appends a new node at the end
    /// </summary>
    /// <param name="head_ref">pointer to pointer of element</param>
    /// <param name="new_data">data that should be after</param>
    void append(const T& new_data);
    /// <summary>
    /// This function prints contents of 
    /// linked list starting from head  
    /// </summary>
    /// <param name="node">pointer to element that should be printed</param>
    void print();
    /// <summary>
    /// show size of this list
    /// </summary>
    /// <returns>unsigned int, object's size</returns>
    size_t sizeRecount();
    /// <summary>
    /// Checks if this element is in list
    /// </summary>
    /// <param name="head">pointer to list</param>
    /// <param name="x">data to be searched</param>
    /// <returns>statement of searching</returns>
    size_t find(const T& x);
    /// <summary>
    /// remove first element
    /// </summary>
    void removeFirst();
    /// <summary>
    /// remove choosen element
    /// </summary>
    /// <param name="position">number of element throught start</param>
    void removePosition(const size_t& position);
    /// <summary>
    /// remove all elements
    /// </summary>
    void removeAll();
    /// <summary>
    /// function that gets data from position of this element, that is bases on counter steps to aim
    /// </summary>
    /// <param name="counter">unsigned int, counter steps to goal</param>
    /// <returns>data that is situated in node that going this steps</returns>
    T get(const size_t& counter);
    /// <summary>
    /// replace data in this list with given data
    /// </summary>
    /// <param name="counter:">counter to replace in the list</param>
    /// <param name="data:">data that should replace old</param>
    void replacement(const size_t& counter, const T& data);
    /// <returns>size of this list</returns>
    size_t size();
private:
    /// <summary>
    /// function that is used to in full get function
    /// </summary>
    /// <param name="node">pointer to Node structure</param>
    /// <param name="counter">steps that this function should follow</param>
    /// <returns>data that is situated in node that going this steps</returns>
    T get(Node* node, const size_t& counter);
    /// <summary>
    /// function to copy one node in this list
    /// </summary>
    /// <param name="node">which information we try to copy</param>
    void copy(const Node*& node);
};

template<typename T>
inline LinkedList<T>::LinkedList()
{
    size_ = 0;
    head_ = nullptr;
    //head->data = 0;
}

template<typename T>
inline LinkedList<T>::LinkedList(const T& data)
{
    head_ = new Node();
    head_->data = data;
    size_ = 1;
}

template<typename T>
inline LinkedList<T>::LinkedList(const LinkedList& rhs)
{
    size_ = rhs.size_;
    if (rhs.head_ != nullptr) {
        head_ = new Node();
        copy(rhs.head_);
    }
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
    delete head_;
    head_ = nullptr;
    size_ = 0;
}

template<typename T>
inline void LinkedList<T>::prepend(const T& new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
    /* 2. put in the data */
    new_node->data = new_data;
    /* 3. Make next of new node as head */
    new_node->next = head_;
    /* 4. move the head to point to the new node */
    head_ = new_node;
    size_++;
}

template<typename T>
inline void LinkedList<T>::insertAfter(const Node*& prev_node, const T& new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == nullptr) {
        std::cout << "the given previous node cannot be NULL";
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

template<typename T>
inline void LinkedList<T>::append(const T& new_data)
{
    /* 1. allocate node */
    size_++;
    Node* new_node = new Node();
    Node* last = head_; /* used in step 5*/
    /* 2. put in the data */
    new_node->data = new_data;
    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    new_node->next = NULL;
    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (head_ == NULL) {
        head_ = new_node;
        return;
    }
    /* 5. Else traverse till the last node */
    while (last->next != NULL) {
        last = last->next;
    }
    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

template<typename T>
inline void LinkedList<T>::print()
{
    const Node* ptr = head_;
    while (ptr != nullptr) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << "\n";
}

template<typename T>
inline size_t LinkedList<T>::sizeRecount()
{
    size_t count = 0; // Initialize count
    const Node* current = head_; // Initialize current
    while (current != nullptr) {
        ++count;
        current = current->next;
    }
    return count;
}

template<typename T>
inline size_t LinkedList<T>::find(const T& x)
{
    size_t counter = 0;
    Node* current = head_; // Initialize current
    while (current != NULL) {
        if (current->data == x) {
            return counter;
        }
        current = current->next;
        counter++;
    }
    return (-1);
}

template<typename T>
inline void LinkedList<T>::removeFirst()
{
    Node* temp = new Node;
    temp = head_;
    head_ = head_->next;
    delete temp;
    size_--;
}

template<typename T>
inline void LinkedList<T>::removePosition(const size_t& position)
{
    Node* current = head_;
    Node* previous = nullptr;
    for (size_t i = 1; i < position; ++i) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    size_--;
}

template<typename T>
inline void LinkedList<T>::removeAll()
{
    while (head_->next != nullptr) {
        removePosition(2);
    }
    removePosition(1);
    size_--;
}

template<typename T>
inline T LinkedList<T>::get(const size_t& counter)
{
    if (counter != 0) {
        get(head_->next, (counter - 1));
    }
    else {
        return head_->data;
    }
}

template<typename T>
inline T LinkedList<T>::get(Node* node, const size_t& counter)
{
    if (counter <= size_) {
        if (counter != 0) {
            get(node->next, (counter - 1));
        }
        else {
            if (node != nullptr) {
                return node->data;
            }
            return -1;
        }
    }
    else {
        return 0;
    }
}

template<typename T>
inline void LinkedList<T>::replacement(const size_t& counter, const T& data)
{
    Node* list = head_;
    if (counter <= size_) {
        if (counter != 0) {
            for (size_t i = 0; i < counter; i++) {
                list = list->next;
            }
        }
    }
    if (list) {
        list->data = data;
    }
}

template<typename T>
inline size_t LinkedList<T>::size()
{
    return size_;
}

template<typename T>
inline void LinkedList<T>::copy(const Node*& node)
{
    if (node) {
        if (node->next != nullptr) {
            head_->next = node->next;
            head_->data = node->data;
            copy(node->next);
        }
    }
}
