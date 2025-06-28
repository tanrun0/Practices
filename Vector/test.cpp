#include "Vector.hpp"

int main()
{
    Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    Vector<int> v2(v1);
    v1.pop_back();
    v1.pop_back();
    v1.erase(v1.begin());
    v1.Print(); // 输出： 2
    v2.insert(v2.begin() + 1, 6);
    v2.Print(); // 输出 16234
    Vector<int> v3(5, 3);
    v3.Print();
    v1.resize(6, 0);
    v1.Print();
    v1.resize(3);
    v1.Print();
    for(int i = 0; i < v1.Size(); i++)
        std::cout << v1[i];
    return 0;
}