// 对于 list 的迭代器，插入元素不会使任何迭代器失效，因为节点是空间是单独开辟的
// 删除元素只会使，被删除节点的迭代器失效

#pragma once
#include <iostream>
#include <cassert>

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
        iterator(Node* node = nullptr) : _node(node) {}
        T& operator*() {return _node->data;}
        T* operator->() {return &_node->data; }
        iterator& operator++(){ _node = _node->next; return *this; }
        iterator& operator--(){ _node = _node->prev; return *this; }
        bool operator==(const iterator& it) {return _node == it._node;}
        bool operator!=(const iterator& it) {return _node != it._node;}
    };

    void push_back(const T& val)
    {
        Node* newnode = new Node(val);
        Node* tail = head->prev; // 尾节点
        tail->next = newnode;
        head->prev = newnode;
        newnode->next = head;
        newnode->prev = tail;
    }

    void push_front(const T& val)
    {
        Node* newnode = new Node(val);
        Node* nxt = head->next;
        nxt->prev = newnode;
        head->next = newnode;
        newnode->next = nxt;
        newnode->prev = head;
    }

    // 默认 pos 是合法的迭代器
    iterator insert(iterator pos, const T& val)
    {
        Node* cur = pos._node;
        Node* prev = cur->prev;
        Node* newnode = new Node(val);
        prev->next = newnode;
        cur->prev = newnode;
        newnode->next = cur;
        newnode->prev = prev;
        return iterator(newnode);
    }

    void pop_back()
    {
        assert(head->next != head && "链表为空");
        Node* del = head->prev;
        del->prev->next = head;
        head->prev = del->prev;
        delete del;
    }

    void pop_front()
    {
        assert(head->next != head && "链表为空");
        Node* del = head->next;
        head->next = del->next;
        del->next->prev = head;
        delete del;
    }

    iterator erase(iterator pos) 
    {
        Node* del = pos._node;
        Node* pre = del->prev;
        Node* nxt = del->next;
        pre->next = nxt;
        nxt->prev = pre;
        delete del;
        return iterator(nxt); // 原来的 next 上提了一个位置
    }

    T& front()
    {
        // 如果断言失败，会把 assert 里面的断言错误信息输出
        assert(head->next != head && "链表为空");
        return head->next->data;
    }

    T& back()
    {
        assert(head->next != head && "链表为空");
        return head->prev->data;
    }

    int size()
    {
        Node* cur = head->next;
        int count = 0;
        while(cur != head)
        {
            count++;
            cur = cur->next;
        }
        return count;
    }

    iterator begin() { return iterator(head->next); }
    iterator end() { return iterator(head); }
    bool empty() const { return head->next == head; }

    void clear()
    {
        Node* del = head->next;
        // 头结点不删
        while(del != head)
        {
            Node* nxt = del->next; // 放在里面，避免无意义的初始化
            delete del;
            del = nxt;
        }
        head->next = head;
        head->prev = head;
    }

    ~List() { clear(); delete head; }
private:
    Node *head; // 哨兵节点，即：链表中始终有一个节点，处理边界情况避免操作空指针
};