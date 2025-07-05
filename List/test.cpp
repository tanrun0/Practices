#include "List.hpp"
#include <iostream>
using namespace std;

int main() {
    List<int> l;

    // 测试 push_back 和 push_front
    l.push_back(1);
    l.push_back(2);
    l.push_front(0);

    cout << "List after push_front and push_back: ";
    for (auto it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // 测试 front/back
    cout << "Front: " << l.front() << ", Back: " << l.back() << endl;

    // 测试 insert
    auto it = l.begin();
    ++it; // 指向第二个元素
    l.insert(it, 100);
    cout << "After insert 100 at second position: ";
    for (auto it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // 测试 erase
    it = l.begin();
    ++it; // 指向100
    l.erase(it);
    cout << "After erase second element: ";
    for (auto it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // 测试 pop_front 和 pop_back
    l.pop_front();
    l.pop_back();
    cout << "After pop_front and pop_back: ";
    for (auto it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // 测试 size 和 empty
    cout << "Size: " << l.size() << ", Empty: " << (l.empty() ? "Yes" : "No") << endl;

    // 测试 clear
    l.clear();
    cout << "After clear, Empty: " << (l.empty() ? "Yes" : "No") << endl;

    return 0;
}