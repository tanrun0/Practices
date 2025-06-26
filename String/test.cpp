#include "String.hpp"

int main()
{
    tr::String s1 = "hello world";
    std::cout << "s1: " << s1.C_str() << std::endl;
    tr::String s2(s1);
    s2 = "nihao"; // 隐式类型转换 + 拷贝赋值
    std::cout << "s2: " << s2.C_str() << std::endl;
    tr::String s3 = s1;
    std::cout << "s3: " << s3.C_str() << std::endl;
    return 0;
}