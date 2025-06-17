#include <iostream>
#include "Heap.hpp"

int main() {
    Heap<int> heap;

    // 插入元素
    heap.insert(3);
    heap.insert(1);
    heap.insert(5);
    heap.insert(2);
    heap.insert(4);

    // 输出堆的大小
    std::cout << "Heap size: " << heap.size() << std::endl;

    // 输出堆顶元素
    std::cout << "Max element: " << heap.getMax() << std::endl;

    // 逐个删除堆顶元素并输出
    while (!heap.isEmpty()) {
        std::cout << "Extracted max: " << heap.extractMax() << std::endl;
    }

    return 0;
}    