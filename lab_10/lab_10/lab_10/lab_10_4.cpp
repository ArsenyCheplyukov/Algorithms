#include <iostream>
#include "FigureList.h"
#include <vector>

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

int main()
{
    {
        GraphObject* ellipse = new Ellipse(1, 2, "magenta", 200, 300);
        GraphObject* rectangle = new Rectangle(3, 4, "yellow", 500, 600);
        GraphObject* star = new Star(5, 6, "cyan", 200, 700, 9);
        GraphObject* polygon = new Polygon(10, 5, "yellow", 50, 43, 4);
        GraphObject* text = new Text(15, 10, "magenta", 10, "SomeText");

        FigureList data(ellipse);
        data.append(rectangle);
        data.append(star);
        data.prepend(polygon);
        data.prepend(text);
        data.removeFirst();
        data.removeAt(1);
        data.print();
    }
    _CrtDumpMemoryLeaks();
    system("pause");
    return 0;
}
