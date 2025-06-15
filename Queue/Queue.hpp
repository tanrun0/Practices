#include <iostream>
#include <cassert>

template <class T>
class Queue
{
private:
    // Node定义的是一个新类型，需要放在前面，不然后面的就不知道Node是什么类型
    struct Node
    {
        T data;
        Node *next;

        Node(const T &val)
            : data(val),
              next(nullptr)
        {
        }
    };

    // 普通成员变量 / 函数在整个类都是可见的（不需要特意定义在前面）
    Node *_front; // 直接指向队头元素
    Node *_rear;  // 直接指向队尾元素
    int _size;

public:
    Queue()
        : _front(nullptr),
          _rear(nullptr),
          _size(0)
    {
    }

    void Push(const T &val)
    {
        Node *newnode = new Node(val);
        if (_size == 0)
        {
            _front = newnode;
            _rear = newnode;
        }
        else
        {
            _rear->next = newnode;
            _rear = _rear->next;
        }
        _size++;
    }

    void Pop()
    {
        assert(_size > 0);
        if (_size == 1)
        {
            delete _rear;
            _rear = _front = nullptr;
        }
        else
        {
            Node *f_pre = _front;
            while (f_pre->next != _rear)
                f_pre = f_pre->next;
            f_pre->next = nullptr;
            delete _rear;
            _rear = f_pre;
        }
        _size--;
    }

    T Front()
    {
        assert(_front != nullptr);
        return _front->data;
    }

    T Back()
    {
        assert(_rear != nullptr);
        return _rear->data;
    }

    void Print()
    {
        Node *cur = _front;
        while (cur)
        {
            std::cout << cur->data << std::endl;
            cur = cur->next;
        }
    }

    int Size()
    {
        return _size;
    }

    bool Empty()
    {
        return _size == 0;
    }

    ~Queue()
    {
    }
};