#pragma once
#include <stdlib.h> 
#include <iostream>
class doors
{
private:
    int m_ID;
    bool m_isOpen{false};

public:
    doors(int ID = 0, bool isOpen = false) : m_ID{ID}, m_isOpen{isOpen} {};
    int click()
    {
        if (m_isOpen)
        {
            return point();
        }
        else
        {
            m_isOpen = true;
            return 0;
        }
    };
    int point()
    {
        return rand() % 10;
    };
    void closeDoor()
    {
        m_isOpen = false;
    }
    void showDoor()
    {
        std::cout << "ID: " << m_ID << ", Is Open? " << std::boolalpha << m_isOpen << '\n';
    }
    ~doors();
};

doors::~doors()
{
}
