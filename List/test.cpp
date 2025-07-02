#include "List.hpp"

int main()
{
    List<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    auto it = l1.begin();

    std::cout << *it << std::endl;
    return 0;
}