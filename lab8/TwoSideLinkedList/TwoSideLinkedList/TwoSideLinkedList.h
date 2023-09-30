#pragma once
#include <iostream> 

// A linked list node  
template<typename T>
class TwoSideLinkedList
{
    struct Node {
        T data;
        Node* next;
        Node* previous;
        ~Node() {
            delete previous;
            delete next;
            next = nullptr;
            previous = nullptr;
        }
    } *head_, *tail_;
    size_t size_;
public:
    /// <summary>
    /// constructor without any parameters
    /// </summary>
    TwoSideLinkedList();
    /// <summary>
    /// constructor that fills first element with some value
    /// </summary>
    /// <param name="number">this some value</param>
    TwoSideLinkedList(const T& data);
    /// <summary>
    /// contructor coping
    /// </summary>
    /// <param name="rhs">object that is need to be copied</param>
    TwoSideLinkedList(const TwoSideLinkedList<T>& rhs);
    // destructor
    virtual ~TwoSideLinkedList();
    /// <summary>
    /// Given a reference (pointer to pointer)
    /// to the head of a listand an int, inserts
    /// a new node on the front of the list.
    /// </summary>
    /// <param name="head_ref"></param>
    /// <param name="new_data"></param>
    void pushFront(const T& new_data);
    /// <summary>
    /// Given a node prev_node, insert a new node after the given
    /// prev_node
    /// </summary>
    /// <param name="prev_node">pointer to item after should element be</param>
    /// <param name="new_data">data that is need to be inserted</param>
    void insertAfter(const Node*& prev_node, const T& new_data);
    /// <summary>
    /// Given a next node, insert a new node after the given
    /// next node
    /// </summary>
    /// <param name="next_node"></param>
    /// <param name="new_data"></param>
    void insertBefore(const Node*& next_node, const T& new_data);
    /// <summary>
    /// Given a reference (pointer to pointer) to the head
    /// of a list and an int, appends a new node at the end
    /// </summary>
    /// <param name="head_ref">pointer to pointer of element</param>
    /// <param name="new_data">data that should be after</param>
    void pushBack(const T& new_data);
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
    void popFront();
    /// <summary>
    /// delete last element
    /// </summary>
    void popBack();
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
    /// gets first element of this list
    /// </summary>
    /// <returns></returns>
    T getHead();
    /// <summary>
    /// gets last element of list
    /// </summary>
    /// <returns>last element's data</returns>
    T getTail();
    /// <summary>
    /// function that gets data from position of this element, that is bases on counter steps to aim
    /// </summary>
    /// <param name="counter">unsigned int, counter steps to goal</param>
    /// <returns>data that is situated in node that going this steps</returns>
    T getStart(const size_t& counter);
    /// <summary>
    /// function that gets data from position of this element from the end, that is bases on counter steps to aim
    /// </summary>
    /// <param name="counter">position from the end</param>
    /// <returns>data that situated in that position</returns>
    T getEnd(const size_t& counter);
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
    T getFromEnd(Node* node, const size_t& counter);
    /// <summary>
    /// function that is used to in full get function of getting element from end
    /// </summary>
    /// <param name="node">pointer to struct</param>
    /// <param name="counter">number of steps that function must pass</param>
    /// <returns>data of element</returns>
    T getFromStart(Node* node, const size_t& counter);
    /// <summary>
    /// function to copy one node in this list
    /// </summary>
    /// <param name="node">which information we try to copy</param>
    void copy(Node* node);
};

template<typename T>
inline TwoSideLinkedList<T>::TwoSideLinkedList()
{
    size_ = 0;
    head_ = nullptr;
    tail_ = nullptr;
}

template<typename T>
inline TwoSideLinkedList<T>::TwoSideLinkedList(const T& data)
{
    head_ = new Node();
    tail_ = head_;
    head_->data = data;
    size_ = 1;
}

template<typename T>
inline TwoSideLinkedList<T>::TwoSideLinkedList(const TwoSideLinkedList<T>& rhs)
{
    size_ = rhs.size_;
    if (rhs.head_ != nullptr) {
        head_ = new Node();
        tail_ = head_;
        copy(rhs.head_);
    }
}

template<typename T>
inline TwoSideLinkedList<T>::~TwoSideLinkedList()
{
    delete head_;
    head_ = nullptr;
    delete tail_;
    tail_ = nullptr;
    size_ = 0;
}

template<typename T>
inline void TwoSideLinkedList<T>::pushFront(const T& new_data)
{
    Node* new_;
    new_ = new Node();
    new_->data = new_data;
    if (head_ == nullptr) {
        tail_ = new_;
    }
    new_->previous = nullptr;
    new_->next = head_;
    head_ = new_;
    if (new_->next != nullptr) {
        new_->next->previous = new_;
    }
    size_++;
}

template<typename T>
inline void TwoSideLinkedList<T>::insertAfter(const Node*& prev_node, const T& new_data)
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
inline void TwoSideLinkedList<T>::insertBefore(const Node*& next_node, const T& new_data)
{
    /*1. check if the given next node is NULL */
    if (next_node == nullptr) {
        std::cout << "the given previous node cannot be NULL";
        return;
    }
    /* 2. allocate new node */
    Node* new_node = new Node();
    /* 3. put in the data */
    new_node->data = new_data;
    /* 4. Make next of new node as next of next node */
    new_node->next = next_node->previous;
    /* 5. move the next of prev_node as new_node */
    next_node->previous = new_node;
    size_++;
}

template<typename T>
inline void TwoSideLinkedList<T>::pushBack(const T& new_data)
{
    if (head_ == nullptr) {
        pushFront(new_data);
        return;
    }
    Node* new_ = new Node();
    new_->data = new_data;
    new_->next = nullptr;
    new_->previous = tail_;
    tail_->next = new_;
    tail_ = new_;
    size_++;
}

template<typename T>
inline void TwoSideLinkedList<T>::print()
{
    const Node* ptr = head_;
    while (ptr != nullptr) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << "\n";
}

template<typename T>
inline size_t TwoSideLinkedList<T>::sizeRecount()
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
inline size_t TwoSideLinkedList<T>::find(const T& x)
{
    size_t counter = 0;
    Node* current = head_; // Initialize current
    while (current != nullptr) {
        if (current->data == x) {
            return counter;
        }
        current = current->next;
        counter++;
    }
    return (-1);
}

template<typename T>
inline void TwoSideLinkedList<T>::popFront()
{
    if (size_) {
        Node* temp = head_;
        if (head_ == tail_) {
            tail_ = nullptr;
        }
        head_ = head_->next;
        size_--;
    }
}

template<typename T>
inline void TwoSideLinkedList<T>::popBack()
{
    if (size_) {
        Node* temp = tail_;
        if (head_ == tail_) {
            head_ = nullptr;
        }
        tail_->next = nullptr;
        tail_ = tail_->previous;
        size_--;
    }
}

template<typename T>
inline void TwoSideLinkedList<T>::removePosition(const size_t& position)
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
inline void TwoSideLinkedList<T>::removeAll()
{
    while (head_->next != nullptr) {
        removePosition(2);
    }
    removePosition(1);
    size_--;
}

template<typename T>
inline T TwoSideLinkedList<T>::getHead()
{
    return head_->data;
}

template<typename T>
inline T TwoSideLinkedList<T>::getTail()
{
    return tail_->data;;
}

template<typename T>
inline T TwoSideLinkedList<T>::getStart(const size_t& counter)
{
    if (counter <= size_) {
        if (counter != 0) {
            getFromStart(head_->next, (counter - 1));
        }
        else {
            return head_->data;
        }
    }
    else {
        return 0;
    }
}

template<typename T>
inline T TwoSideLinkedList<T>::getEnd(const size_t& counter)
{
    if (counter <= size_) {
        if (counter != 0) {
            getFromEnd(tail_->previous, (counter - 1));
        }
        else {
            return tail_->data;
        }
    }
    else {
        return 0;
    }
}

template<typename T>
inline T TwoSideLinkedList<T>::getFromEnd(Node* node, const size_t& counter)
{
    if (counter != 0) {
        getFromEnd(node->previous, (counter - 1));
    }
    else {
        if (node != nullptr) {
            return node->data;
        }
        return -1;
    }
}

template<typename T>
inline T TwoSideLinkedList<T>::getFromStart(Node* node, const size_t& counter)
{
    if (counter != 0) {
        getFromStart(node->next, (counter - 1));
    }
    else {
        if (node != nullptr) {
            return node->data;
        }
        return -1;
    }
}

template<typename T>
inline void TwoSideLinkedList<T>::replacement(const size_t& counter, const T& data)
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
inline size_t TwoSideLinkedList<T>::size()
{
    return size_;
}

template<typename T>
inline void TwoSideLinkedList<T>::copy(Node* node)
{
    if (node != nullptr) {
        if (node->next != nullptr) {
            head_->next = node->next;
            head_->previous = node->previous;
            head_->data = node->data;
            copy(node->next);
        }
    }
}
