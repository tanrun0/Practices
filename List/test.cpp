#include "List.hpp"

int main()
{
    List<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    for(auto x: l1)
    {
        std::cout << x << " ";
    }
    return 0;
}