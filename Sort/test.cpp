#include "Sort.hpp"

#define n 10
int main()
{
    std::vector<int> arr = {2, 3, 4, 5, 7, 1, 9, 0, 6,8};
    BubbleSort(arr);
    Print(arr, "BubbleSort");
    InsertSort(arr);
    Print(arr, "InsertSort");
    ShellSort(arr);
    Print(arr, "ShellSort");
    HeapSort(arr);
    Print(arr, "HeapSort");
    QuickSort(arr, 0, arr.size() - 1);
    Print(arr, "QuickSort");
    return 0;
}