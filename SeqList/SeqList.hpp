#pragma once
#include <iostream>
#include <cassert>

namespace tr
{
    template <class T>
    class SeqList
    {
    public:
        // 在构造的时候完成初始化
        SeqList(int size = 4)
            : _MaxSize(size),
              _length(0)
        {
            _data = new T[_MaxSize];
            std::cout << "创建线性表成功" << std::endl;
        }

        // 检查是否需要扩容，如果需要就扩容
        bool CheckCapacity()
        {
            if (_length == _MaxSize)
            {
                int newSize = _MaxSize * 2;
                T *newdata = new T[newSize];
                if (newdata == nullptr)
                    perror("扩容失败");

                // 复制数据
                for (int i = 0; i < _length; i++)
                    newdata[i] = _data[i];

                delete[] _data;
                _data = newdata;
                _MaxSize = newSize;
                std::cout << "大小不足，自动扩容" << std::endl;
                return true;
            }
            return false;
        }

        // 头插
        void PushFront(const T &val)
        {
            CheckCapacity();
            for (int i = 0; i < _length; i++)
                _data[i + 1] = _data[i];
            _data[0] = val;
            _length++;
        }

        // 尾插
        void PushBack(const T &val)
        {
            CheckCapacity();
            _data[_length] = val;
            _length++;
        }

        // 头删
        void PopFront()
        {
            for (int i = 1; i < _length; i++)
                _data[i - 1] = _data[i];
            _length--;
        }

        // 尾删
        void PopBack()
        {
            _length--;
        }

        // 在 pos 位置插入
        void Insert(const int &pos, const T &val)
        {
            assert(pos >= 0 && pos <= _length);
            CheckCapacity();
            for (int i = pos; i < _length; i++)
                _data[i + 1] = _data[i];
            _data[pos] = val;
            _length++;
        }

        // 删除 pos 位置
        void Erase(const int &pos, T *outval)
        {
            assert(pos >= 0 && pos < _length);
            *outval = _data[pos];
            for (int i = pos; i < _length; i++)
                _data[i] = _data[i + 1];
            _length--;
        }

        // 打印
        void Print()
        {
            for (int i = 0; i < _length; i++)
                std::cout << _data[i] << " ";
            std::cout << std::endl;
        }

        // 析构的时候完成销毁
        ~SeqList()
        {
            delete[] _data;
            std::cout << "销毁线性表成功" << std::endl;
        }

        int GetLength()
        {
            return _length;
        }

    private:
        T *_data;    // 线性表数据存储区（一块连续的空间）
        int _MaxSize;
        int _length;
    };

}
