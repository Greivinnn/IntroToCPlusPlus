#include <iostream>
#include <stdexcept>

void ProcessPositive(int num)
{
    if (num > 100)
    {
        std::cout << "ProcessPositive says there is an error";
    }
}

void DoSomething(int num)
{
    try
    {
        if (num < 0)
        {
            throw std::invalid_argument("Number must be positive bro");
        }
    }
    catch (std::invalid_argument ex)
    {
        std::cout << "DoSomething says there is an error\n";
        throw;
        
    }
    catch (std::out_of_range ex)
    {
        std::cout << "DoSomething says number is too big\n";
        throw;
    }
}

int main()
{
    int input;


}
