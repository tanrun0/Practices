#include "SeqList.hpp"

int main()
{
    std::cout << "-----------线性表测试开始------------" << std::endl;
    tr::SeqList<int> sq1;
    sq1.PushFront(2);
    sq1.Insert(0, 1);
    sq1.Insert(2, 3);
    sq1.PushBack(4);
    sq1.Print();
    std::cout << "当前大小: " << sq1.GetLength() << std::endl;
    sq1.PushBack(5);
    sq1.PushBack(6);
    sq1.PushBack(7);
    sq1.Print();
    std::cout << "当前大小: " << sq1.GetLength() << std::endl;
    sq1.PopBack();
    sq1.PopFront();
    sq1.Print();
    int outval;
    sq1.Erase(1, &outval);
    std::cout << "删除的下标位置为 1 的元素是: " << outval << std::endl;
    sq1.Print();
    std::cout << "当前大小: " << sq1.GetLength() << std::endl;
    std::cout << "--------线性表测试完成------------" << std::endl;
    return 0;
}