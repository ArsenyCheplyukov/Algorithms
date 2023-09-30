// TwoSideLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "TwoSideLinkedList.h"

size_t findMax(std::vector<size_t> data) {
    size_t max = data.at(0);
    for (size_t i = 0; i < data.size(); ++i) {
        if (max < data.at(i)) {
            max = data.at(i);
        }
    }
    return max;
}

int main()
{
    std::vector<size_t> data;
    TwoSideLinkedList<size_t> List_1;
    List_1.pushFront(5);
    List_1.pushFront(8);
    List_1.pushBack(10);
    List_1.pushFront(4);
    List_1.pushFront(5);
    List_1.pushFront(80);
    List_1.pushBack(68);
    List_1.pushFront(15);
    List_1.pushFront(13);
    List_1.pushFront(56);
    List_1.pushBack(36);
    List_1.pushFront(85);
    size_t half_size = List_1.size() / 2;
    List_1.print();
    for (size_t i = 0; i < half_size; i++) {
        data.push_back(List_1.getStart(i) + List_1.getEnd(i));
    }
    std::cout << "The max element is: " << findMax(data) << std::endl;
    system("pause");
    return 0;
}

