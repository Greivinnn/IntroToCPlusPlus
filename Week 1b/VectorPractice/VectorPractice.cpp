#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> vec{"Daniel", "Jose", "Isabella", "Wanda", "Joselu"};

    vec.insert(vec.begin() + 2, "Greivin");
    vec.erase(vec.end() - 1);



    return 0;
}
