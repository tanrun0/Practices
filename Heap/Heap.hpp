#include <vector>

// 实现大根堆
template<typename T>
class Heap
{
private:
    std::vector<T> _data; // 用 vector 来模拟树

    void swap(int i, int j)
    {
        int tmp = _data[i];
        _data[i] = _data[j];
        _data[j] = tmp;
    }

    void siftUp(int index) // 从 index 位置开始，向上调整
    {
        while(index > 0)
        {
            int parent = (index - 1) / 2;
            if(_data[parent] >= _data[index])
                break;
            swap(index, parent);
            index = parent;
        }
    }

    void siftDown(int index) 
    {
        int largest = index * 2 + 1; // 先默认左孩子是最大的
        int size = _data.size();
        while(largest < size)
        {
            if(largest + 1 < size && _data[largest + 1] > _data[largest]) // 如果右孩子存在并且比左孩子大
                largest += 1; 
            if(_data[index] > _data[largest])
                break;
            swap(index, largest);
            index = largest; // 更新父亲节点
            largest = index * 2 + 1; // 更新下一个要判断的孩子节点
        } 
    }

public:
    void insert(const T& value) 
    {
        _data.push_back(value);
        siftUp(_data.size() - 1);
    }

    // 删除并返回堆顶元素
    T extractMax() 
    {
        if (_data.empty()) 
        {
            throw std::out_of_range("Heap is empty");
        }

        // 交换堆顶和最后一个元素，然后把堆顶 pop 出去(此时已经是 max)，再向下调整
        T max = _data[0];
        _data[0] = _data.back();
        _data.pop_back();
        siftDown(0);
        return max;
    }

    // 获取堆顶元素
    T getMax() const 
    {
        if (_data.empty()) 
        {
            throw std::out_of_range("Heap is empty");
        }
        return _data[0];
    }


    // const 对象不能调用非 const 成员函数，但是普通对象可以调 const
    // const 成员函数不能直接修改对象的任何非静态数据成员（除非该成员被声明为 mutable）
    // 普通对象可以调用 const 成员函数
    // 判断堆是否为空
    bool isEmpty() const 
    {
        return _data.empty();
    }

    // 获取堆的大小
    int size() const  
    {
        return _data.size();
    }
};