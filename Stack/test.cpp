#include "Stack.hpp"


int main() {
    // 测试int类型的栈
    tr::Stack<int> intStack(2);
    
    // 测试Empty和Size方法
    assert(intStack.Empty() == true);
    assert(intStack.Size() == 0);
    
    // 测试Push方法
    intStack.Push(10);
    intStack.Push(20);
    assert(intStack.Empty() == false);
    assert(intStack.Size() == 2);
    
    // 测试扩容
    intStack.Push(30);
    assert(intStack.Size() == 3);
    assert(intStack.Top() == 30);
    
    // 测试Pop方法
    intStack.Pop();
    assert(intStack.Size() == 2);
    assert(intStack.Top() == 20);
    
    // 测试Top方法
    assert(intStack.Top() == 20);
    
    // 清空栈
    intStack.Pop();
    intStack.Pop();
    assert(intStack.Empty() == true);
    
    // 测试double类型的栈
    tr::Stack<double> doubleStack(1);
    doubleStack.Push(3.14);
    doubleStack.Push(2.718);
    assert(doubleStack.Size() == 2);
    assert(doubleStack.Top() == 2.718);
    
    std::cout << "所有测试用例均通过！" << std::endl;
    
    return 0;
}    