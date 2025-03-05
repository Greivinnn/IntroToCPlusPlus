#include <iostream>
#include "Calculator.h"

using namespace std;

int main()
{
    Calculator calc;
    cout << "Integer addition: " << calc.Add(3, 5) << endl;
    cout << "Double addition: " << calc.Add(3.5, 5.5) << endl;

    return 0;
}