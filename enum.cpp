#include <iostream>

enum class MyEnum : int
{
    StartValue = 0xFF,
    Item1 = 0,
    Item2,
    Item3,
};

int main()
{
    std::cout << "start value: " << static_cast<int>(MyEnum::StartValue) << std::endl;
    std::cout << "item 1: " << static_cast<int>(MyEnum::Item1) << std::endl;
    std::cout << "item 2: " << static_cast<int>(MyEnum::Item2) << std::endl;
    std::cout << "item 3: " << static_cast<int>(MyEnum::Item3) << std::endl;

    return 0;
}

