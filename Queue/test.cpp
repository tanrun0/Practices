#include "Queue.hpp"

int main() {
    // 测试默认构造函数
    Queue<int> q;
    std::cout << "队列初始化后是否为空: " << (q.Empty() ? "是" : "否") << std::endl;

    // 测试Push和Front方法
    q.Push(10);
    q.Push(20);
    q.Push(30);
    std::cout << "队列头部元素: " << q.Front() << std::endl;
    std::cout << "队列尾部元素: " << q.Back() << std::endl;
    std::cout << "队列大小: " << q.Size() << std::endl;

    // 测试Pop方法
    q.Pop();
    std::cout << "执行一次Pop后，队列头部元素: " << q.Front() << std::endl;
    std::cout << "队列大小: " << q.Size() << std::endl;

    // 测试Print方法
    std::cout << "队列所有元素:" << std::endl;
    q.Print();

    // 测试空队列Pop的异常处理（会触发assertion失败）
    // 注意：取消下面注释会导致程序崩溃，用于测试assert功能
    // Queue<int> emptyQueue;
    // emptyQueue.Pop();

    // 测试连续Pop到空
    q.Pop();
    q.Pop();
    std::cout << "执行两次Pop后，队列是否为空: " << (q.Empty() ? "是" : "否") << std::endl;

    // 测试空队列Front的异常处理（会触发assertion失败）
    // 注意：取消下面注释会导致程序崩溃，用于测试assert功能
    // std::cout << "空队列的头部元素: " << q.Front() << std::endl;

    // 测试在空队列后再次Push
    q.Push(100);
    std::cout << "空队列Push后，队列头部元素: " << q.Front() << std::endl;

    return 0;
}