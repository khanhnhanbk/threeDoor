#pragma once
#include <stdlib.h>
#include <iostream>
class doors
{
private:
    int m_ID;
    bool m_isOpen{false};
    int m_point{0};

public:
    doors(int ID = 0, bool isOpen = false) : m_ID{ID}, m_isOpen{isOpen}
    {
    };
    int click()
    {
        if (m_isOpen)
        {
            return point();
        }
        else
        {
            m_isOpen = true;
            updatePoint();
            showDoor();
            return 0;
        }
    };
    void updatePoint()
    {
        m_point = rand() % 1000 + 1;
    }
    int getID()
    {
        return m_ID;
    }
    int point()
    {
        return m_point;
    };
    void closeDoor()
    {
        m_isOpen = false;
    }
    void showDoor()
    {
        std::cout << "ID: " << m_ID << ", Is Open? " << std::boolalpha << m_isOpen << " point: " << m_point << '\n';
    }
    ~doors();
};

doors::~doors()
{
}
