#include "BidList.hpp"

int main() {
    // 创建一个整数链表
    BidList<int> intList;

    // 测试 PushBack
    std::cout << "Testing PushBack:" << std::endl;
    intList.PushBack(1);
    intList.PushBack(2);
    intList.PushBack(3);
    intList.Print();  // 预期输出: 1 2 3

    // 测试 PushFront
    std::cout << "\nTesting PushFront:" << std::endl;
    intList.PushFront(0);
    intList.PushFront(-1);
    intList.Print();  // 预期输出: -1 0 1 2 3

    // 测试 PopFront
    std::cout << "\nTesting PopFront:" << std::endl;
    intList.PopFront();
    intList.Print();  // 预期输出: 0 1 2 3

    // 测试 PopBack
    std::cout << "\nTesting PopBack:" << std::endl;
    intList.PopBack();
    intList.Print();  // 预期输出: 0 1 2

    // 测试 Find
    std::cout << "\nTesting Find:" << std::endl;
    if (intList.Find(1) != nullptr) {
        std::cout << "Found: " << intList.Find(1)->val << std::endl;  // 预期输出: Found: 1
    } else {
        std::cout << "Not found" << std::endl;
    }

    // 测试 Insert
    std::cout << "\nTesting Insert:" << std::endl;
    intList.Insert(5, 1);  // 在位置 1 插入 5
    intList.Print();       // 预期输出: 0 5 1 2

    // 测试 Erase
    std::cout << "\nTesting Erase:" << std::endl;
    intList.Erase(2);
    intList.Print();  // 预期输出: 0 5 2

    return 0;
}