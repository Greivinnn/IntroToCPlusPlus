#include <iostream>
#include "House.h"

using namespace std;

House::House(string c, int s, int w) :
    _color(c), _stories(s), _windows(w) {}

void House::PrintHouseData() {
    cout << "Color: " << _color << ", Stories: " << _stories << ", Windows: " << _windows << endl;
}