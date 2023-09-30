// lab_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
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

//int main()
//{
//    GraphObject* ellipse = new Ellipse(1, 2, "magenta", 200, 300);
//    GraphObject* rectangle = new Rectangle(3,4, "yellow", 500, 600);
//    GraphObject* star = new Star(5,6, "cyan", 200, 700, 9);
//    GraphObject* polygon = new Polygon(10, 5, "yellow", 50, 43, 4);
//    GraphObject* text = new Text(15, 10, "magenta", 10, "SomeText");
//    ArrayFigures data(ellipse);
//    data.add(rectangle);
//    data.add(star);
//    data.add(polygon);
//    data.add(text);
//    data.print();
//    _CrtDumpMemoryLeaks();
//    system("pause");
//    return 0;
//}

