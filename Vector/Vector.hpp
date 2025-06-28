#pragma once
#include <iostream>
#include <cassert>
template <class T>
class Vector
{
public:
    // 用指针封装 iterator
    typedef T *iterator;
    typedef const T *const_iterator;

    int Size() const
    {
        if (_start == nullptr)
            return 0;
        return _end - _start; // 某些编译器下 nullptr - nullptr == 0
    }

    bool Empty() { return Size() == 0; }

    iterator begin() { return _start; }
    iterator end() { return _end; }
    const_iterator begin() const { return _start; }
    const_iterator end() const { return _end; }

    void reserve(int n)
    {
        if (n > _capacity)
        {
            int oldsize = Size();
            T *tmp = new T[n];
            for (int i = 0; i < oldsize; i++)
                tmp[i] = _start[i];

            delete[] _start;  // delete nullptr 是安全的
            _start = tmp;
            _end = tmp + oldsize;
            _capacity = n;
        }
    }

    void resize(int n, const T &val = T())
    {
        if (n < Size())
            _end = _start + n;
        else
        {
            reserve(n);
            while (_end != _start + n) // 把后面的填上 val
                *_end++ = val;
        }
    }

    Vector() = default;

    Vector(const Vector<T> &v)
    {
        reserve(v.Size());
        for (auto &x : v)
            push_back(x);
    }

    Vector(int size, const T &val = T())
    {
        reserve(size);
        for (int i = 0; i < size; i++)
            push_back(val);
    }

    void push_back(const T &val)
    {
        if (_capacity == Size())
            reserve(_capacity == 0 ? 4 : _capacity * 2);
        *_end = val;
        _end++;
    }

    void pop_back()
    {
        assert(Size() > 0);
        _end--;
    }

    iterator insert(iterator pos, const T &val) // 默认 pos 存在
    {
        assert(pos >= _start && pos <= _end);

        size_t offset = pos - _start; // 处理迭代器失效的问题
        if (_capacity == Size())
            reserve(_capacity == 0 ? 4 : _capacity * 2);
        pos = _start + offset;
        // 因为我们的 iterator 是 typedef 来的, 其实就是指针，所以是支持++
        for (iterator cur = _end - 1; cur >= pos; cur--)
            *(cur + 1) = *cur; // 元素后移
        *pos = val;
        _end++;
        return pos;  // 当因为reserve扩容导致的迭代器失效，那么这个pos就不一样了
    }

    iterator erase(iterator pos)
    {
        assert(pos >= _start && pos < _end);
        for (iterator cur = pos + 1; cur < _end; cur++)
            *(cur - 1) = *cur;
        _end--;
        return pos; // pos就是删除后，原来元素的下一个位置（erase没有对内存进行重新分配，没有迭代器失效的问题）
    }

    void Print()
    {
        for (int i = 0; i < Size(); i++)
            std::cout << _start[i];
        std::cout << std::endl;
    }

    T& operator[](int pos) const 
    {
        assert(pos >= 0 && pos < Size());
        return _start[pos];
    }

    ~Vector()
    {
        delete[] _start;
    }

private:
    // 哥缺省值，因为在拷贝构造的时候也会依赖 _end 的初始值，指针要初始化
    T *_start = nullptr;     // 指向第一个元素
    T *_end = nullptr;       // 指向最后一个元素的后一个（和迭代器统一）
    int _capacity = 0; // 容量大小
};