#include <iostream>
#include "doors.h"

using namespace std;
int Show(int clickLeft, int point)
{
    cout << point << '\n';
    cout << "You have " << clickLeft << " times left\n";
    cout << "Which door do you choose? (1, 2, 3): ";
    int n;
    cin >> n;
    system("cls");
    return n;
}
int main()
{
    doors *door;
    door = new doors[3]{doors(1), doors(2), doors(3)};
    // for (int i = 0; i < 3; i++)
    // {
    //     door[i].showDoor();
    // }

    cout << "-----------------------------------\n\n";
    cout << "You have three doors and 100 mouse clicks. Each door opening takes one click. Once the door is open, just click to get points. You can open other doors and get points there. Then the door you are opening will close. After 100 mouse clicks, it will summarize.\n\n";
    system("pause");
    int clickLeft{100};
    int current{0};
    int point{0};
    while (clickLeft > 0)
    {
        current = Show(clickLeft, point);
        for (int i = 0; i < 3; i++)
        {
            if (current == door[i].getID())
                point += door[i].click();
            else
            {
                door[i].closeDoor();
            }
        }
        clickLeft--;
    }
    delete[] door;
    return 0;
}