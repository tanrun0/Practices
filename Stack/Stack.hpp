#include <iostream>
#include <cassert>

namespace tr
{
    template <class T>
    class Stack
    {
    public:
        Stack(int capacity)
              :_capacity(capacity),
              _top(-1)
        {
            _data = new T[_capacity];
        }

        void resize()
        {
            _capacity *= 2;
            T* newdata = new T[_capacity];
            for(int i = 0; i <= _top; i++)
                newdata[i] = _data[i];
            delete[] _data;
            _data = newdata;
        }
        void Push(const T &val)
        {
            if(_top + 1 == _capacity)
                resize();
            _data[++_top] = val;
        }

        void Pop()
        {
            assert(_top >= 0);
            _top--;
        }

        T Top()
        {
            return _data[_top];
        }

        int Size()
        {
            return _top + 1;
        }

        bool Empty()
        {
            return _top == -1;
        }

        ~Stack()
        {
            delete[] _data;
        }

    private:
        T *_data;      // 存放元素的数组，data[]: 下标访问本质是靠指针 + 偏移量
        int _top;      // 栈顶元素下标
        int _capacity = 4; // 当前栈容量大小（ 默认为 4 ）
    };

} // namespace tr
