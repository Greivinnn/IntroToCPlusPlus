#include <iostream>
#include <array>
#include <time.h>

int main()
{
    srand(time(NULL));

    int sum = 0;

    int randomNum1 = rand() % 50 + 51;
    int randomNum2 = rand() % 50 + 51;
    int randomNum3 = rand() % 50 + 51;
    int randomNum4 = rand() % 50 + 51;
    int randomNum5 = rand() % 50 + 51;

    std::array<int, 5> arr = { randomNum1, randomNum2, randomNum3, randomNum4, randomNum5 };

    std::cout << "Array Elements: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n";

    for (int i = 0; i < 5; i++)
    {
        sum = sum + arr[i];
    }
    std::cout << "All numbers added together = " << sum;
}