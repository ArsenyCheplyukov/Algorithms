// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"

template<typename T>
size_t findPosition(LinkedList<T>& some_list, LinkedList<T>& another_list)
{
    size_t some_size = some_list.size();
    size_t another_size = another_list.size();
    int delta = some_size - another_size;
    if (delta < 0) {
        return -1;
    }
    for (size_t i = 0; i <= delta; ++i) {
        bool having = true;
        for (size_t j = 0; j <= another_size; j++) {
            if (some_list.get(i + j) != another_list.get(j)) {
                having = false;
                break;
            }
        }
        if (having) {
            return i;
        }
    }
    return size_t(-1);
}

template<typename T>
void replacementInList(LinkedList<T>& L, LinkedList<T>& L1, LinkedList<T>& L2)
{
    size_t position = findPosition(L, L1);
    if (position != -1) {
        size_t size = L2.size();
        for (size_t i = 0; i < size; ++i) {
            L.replacement(position + i, L2.get(i));
        }
    }
}

int main()
{
    LinkedList<size_t> L, L1(7), L2(1);
    L.append(3);
    L.append(5);
    L.append(7);
    L.append(9);
    std::cout << "L list is:";
    L.print();
    std::cout << "L1 list is:";
    L1.append(9);
    L1.print();
    std::cout << "L2 list is:";
    L2.append(1);
    L2.print();
    replacementInList(L, L1, L2);
    std::cout << "And new A list is: \n";
    L.print();
    system("pause");
    return 0;
}

