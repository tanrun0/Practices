#include <iostream>
#include <vector>
#include <string>
void Print(std::vector<int> & arr, std::string s)
{
    std::cout << "----------------" << s << "----------------" << std::endl;
    for(int i = 0; i < arr.size(); i++)
        std::cout << arr[i];
    std::cout << std::endl;
}

// 一、交换排序
// 1. 冒泡排序
void BubbleSort(std::vector<int> & arr)
{
    int n = arr.size();
    for(int i = 0;  i < n - 1; i++) // 总共排 n - 1 趟
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

// 2. 快速排序
void QuickSort(std::vector<int> & arr)
{


}


// 二、插入排序
// 1. 直接插入排序(分为已排序区 和 未排序区，每次把从未排序区选一个元素key插入到已排序区的正确位置)
void InsertSort(std::vector<int> & arr)
{
    int n = arr.size();
    for(int i = 1; i < n; i++)
    {
        int key = arr[i]; // 要插入的元素
        int j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}