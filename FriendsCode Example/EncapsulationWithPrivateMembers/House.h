#pragma once

#include <iostream>

using namespace std;

class House
{
public:
    House(string c, int s, int w);

    void PrintHouseData();

private:
    string _color;
    int _stories;
    int _windows;
};