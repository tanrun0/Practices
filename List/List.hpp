// 对于 list 的迭代器，插入元素不会使任何迭代器失效，因为节点是空间是单独开辟的
// 删除元素只会使，被删除节点的迭代器失效

#pragma once
#include <iostream>

template <class T>
struct ListNode
{
    ListNode *prev;
    ListNode *next;
    T data;
    ListNode(const T &val = T()) : prev(nullptr), next(nullptr), data(val) {}
};

template <class T>
class List
{
public:
    typedef ListNode<T> Node;
    List()
    {
        head = new Node();
        head->next = head;
        head->prev = head;
    }

    class iterator
    {
    public:
        Node* _node; // 迭代器底层用指针封装
        iterator() : _node(nullptr) {}
        T& operator*() {return _node->data;}
        T* operator->() {return &_node->data; }
        iterator& operator++(){ _node = _node->next; return *this};
        iterator& operator--(){ _node = _node->prev; return *this};
        bool operator==(const iterator& it) (return _node == it._node);
        bool operator==(const iterator& it) (return _node != it._node);
    };

private:
    Node *head; // 哨兵节点，即：链表中始终有一个节点，处理边界情况避免操作空指针
};