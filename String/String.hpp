// 模拟实现 stirng 类
// 要求有：1. 构造; 2. 拷贝构造; 3. 移动构造
// 其他基本的接口：1. 获取大小; 2. 判读是否为空;3. 转换成 C 风格字符串
// 运算符重载: [], >, +, = (拷贝赋值 and 移动赋值)

#include<cstring>
#include<iostream>

namespace tr
{
    class String
    {
    public:
        String() // 默认构造
        {
            _data = new char[1];
            _data[0] = '\0';
            _size = 0;
        }
        String(const char* str) // 用 C 风格字符串构造
        {
            _size = strlen(str);
            _data = new char[_size + 1];
            std::strcpy(_data, str);
        }
        String(const String& str) // 拷贝构造
        {
            _size = str.Size();
            _data = new char[_size + 1];
            std::strcpy(_data, str._data);
        }

        int Size() const // const 成员不能调用非 const成员函数，因为怕成员被修改
        {
            return _size;
        }

        bool Empty()
        {
            return _size == 0;
        }

        const char * C_str() const 
        {
            return _data;
        }

        // 返回引用减少拷贝
        String& operator=(String str)
        {
            // 函数内部的 str 是拷贝（形参）
            std::swap(_data, str._data);
            std::swap(_size, str._size);
            return *this; // 为了实现连续赋值，第二次把引用作为参数传给 str 的时候会隐式转换，拷贝引用指向的对象
        }

        ~String()
        {
            delete[] _data;
        }
        private:
        char *_data;
        int _size;
    };
}