#include <iostream>
using namespace std;

class A
{
private:
    static int _k;
    int _h = 1;
public:
    class B
    {
    private:
        int _n;

    public:
        void foo(const A &a)
        {
            cout << _k << endl;
            cout << a._h << endl;
        }
    };

    // 错误的: 外部类不是内部类的友元
    // void foo2(const B & b)
    // {
    //     cout << b._n << endl;
    // }
};

int A::_k = 1;
int main()
{
    A::B b;
    A aa;
    b.foo(aa);
    return 0;
}