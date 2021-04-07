#include <iostream>
#include "doors.h"

using namespace std;

int main()
{
    doors *door;
    door = new doors[3] {doors(0), doors(1), doors(2)};
    for (int i = 0; i < 3; i++)
    {
        door[i].showDoor();
    }
    delete[] door;
    return 0;
}