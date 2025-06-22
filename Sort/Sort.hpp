#include <iostream>
#include <vector>
#include <string>
void Print(std::vector<int> &arr, std::string s)
{
    std::cout << "----------------" << s << "----------------" << std::endl;
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i];
    std::cout << std::endl;
}

// 一、交换排序
// 1. 冒泡排序
void BubbleSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) // 总共排 n - 1 趟
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

// 2. 快速排序（选一个 Key 作为基准，把原区间划分成 "已经排序好" 的区间）
void QuickSort(std::vector<int> &arr, int left, int right) // [left, right)
{
    if(left + 1 >= right) return;
    int key = arr[left]; // 选区间第一个元素为基准
    int i = left; // 指向 <= key 区间的边界 (初始时区间为空，注意要略过第一个基准元素)
    for(int j = left + 1; j < right; j++) // 从基准后一个位置开始分区
    {
        if(arr[j] < key)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[left], arr[i]); // 把基准和 <= key 区间的最后一个元素进行交换，让基准位于中间
    QuickSort(arr, left, i);
    QuickSort(arr, i + 1, right);
}

// 二、插入排序
// 1. 直接插入排序(分为已排序区 和 未排序区，每次把从未排序区选一个元素key插入到已排序区的正确位置)
void InsertSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // 要插入的元素
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 希尔排序
// 选择增量（对不同增量（增量逐渐减小）进行插入排序），增量是元素之间的间隔
// 不同增量对应一个子序列，在子序列内做希尔排序的时候，不同的时候元素之间的间隔不同
void ShellSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int gap = n / 2; gap >= 1; gap /= 2)
    {
        for (int i = gap; i < n; i++) // 遍历每一个分组的第二个元素
        {
            int key = arr[i]; // 要插入的元素
            int j = i - gap;  // 要插入元素的前一个元素
            while (j >= 0 && arr[j] > key)
            {
                arr[j + gap] = arr[j];
                j += gap;
            }
        }
    }
}

// 堆排序
// 我们把堆定大的元素依次放到数组的最后，所以要大根堆
void AdjustDwon(std::vector<int> &arr, int n, int i)  // n : 没排序好的元素的个数
{
    int child = i * 2 + 1;
    while (child < n)
    {
        if (child + 1 < n && arr[child + 1] > arr[child])
            child++;
        if (arr[i] > arr[child])
            break;
        std::swap(arr[i], arr[child]);
        i = child;
        child = i * 2 + 1;
    }
}

void HeapSort(std::vector<int> &arr)
{
    int n = arr.size();
    // 先建堆
    for (int i = n / 2 - 1; i >= 0; i--) // 从非叶子节点开始调整 -> 建堆
        AdjustDwon(arr, n, i);
    for(int i = n - 1; i >= 1; i--) // 每次排好一个元素，待排序的“堆”越来越小
    {
        // 把堆顶和当前堆最后一个元素交换-> 排序
        std::swap(arr[0], arr[i]);
        // 调整堆，注意：此时已经排好了一个元素，堆应该缩小
        AdjustDwon(arr, i, 0);
    }
}

// 归并排序
void MergeSort(std::vector<int> &arr)
{

}
