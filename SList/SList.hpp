#include <iostream>
#include <cassert>
// 1、无头 + 单向 + 非循环链表增删查改实现
template <class T>
struct Node
{
    T data;
    Node *next;

    Node(const T &val)
        : data(val), next(nullptr)
    {
    }
};

template <class T>
class SList
{
public:
    SList()
        : _head(nullptr)
    {
    }
    void Print()
    {
        Node<T> *cur = _head;
        while (cur)
        {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }

    void PushBack(const T &val)
    {
        if (_head == nullptr)
            _head = new Node<T>(val);
        else
        {
            Node<T> *cur = _head;
            while (cur->next) // 找到最后一个节点
                cur = cur->next;
            cur->next = new Node<T>(val);
        }
    }

    void PushFront(const T &val)
    {
        if (_head == nullptr)
            _head = new Node<T>(val);
        else
        {
            Node<T> *newnode = new Node<T>(val);
            newnode->next = _head;
            _head = newnode;
        }
    }

    void PopBack()
    {
        assert(_head);
        if (!_head->next) // 只有一个 _head
        {
            delete _head;
            _head = nullptr;
        }
        else
        {
            Node<T> *front = _head;
            Node<T> *cur = _head->next;
            while (cur->next)
            {
                cur = cur->next;
                front = front->next;
            }
            front->next = cur->next;
            delete cur;
        }
    }

    void PopFront()
    {
        assert(_head);
        Node<T>* f = _head;
        _head = _head->next;
        delete f;
    }

    Node<T> *Find(const T &val)
    {
        Node<T> *cur = _head;
        while (cur)
        {
            if (cur->data == val)
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    // 在链表的第 pos 个位置插入节点 （下标从 0 开始）
    void Insert(const T &val, int pos)
    {
        assert(pos >= 0); // 代表下标非法
        if (pos == 0)
            PushFront(val);
        Node<T> *cur = _head;
        // 移动 pos - 1 步，cur 到达 pos - 1位置的节点
        for (int i = 0; i < pos - 1 && !cur; i++)
            cur = cur->next;
        assert(cur != nullptr); // 代表下标非法
        Node<T> *newnode = new Node<T>(val);
        newnode->next = cur->next;
        cur->next = newnode;
    }

    void Erase(int pos, T *val)
    {
        assert(pos >= 0 || _head != nullptr);
        Node<T>* prev = nullptr;
        Node<T> *cur = _head;
        for (int i = 0; i < pos && cur; i++)
        {
            prev = cur;
            cur = cur->next;
        }
        assert(cur != nullptr);
        *val = cur->data;
        prev->next = cur->next;
        delete cur;
    }
    ~SList()
    {
        if(_head)
        {
            Node<T>* cur = _head;
            while(cur->next)
            {
                Node<T>* nxt = cur->next;
                delete cur;
                cur = nxt;
            }
            delete cur;
        }
    }

private:
    Node<T> *_head; // 指向链表第一个节点
};