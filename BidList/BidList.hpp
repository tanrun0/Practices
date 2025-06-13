#include <iostream>
#include <cassert>

// 带头双向循环链表，让最后一个节点的 next 指向哨兵头节点
template <class T>
class BidList
{
public:
    // 链表节点，放在里面可以直接用模板类型
    struct Node
    {
        Node(const T &v)
            : val(v), prev(nullptr), next(nullptr)
        {
        }
        T val;
        Node *prev;
        Node *next;
    };

    BidList()
    {
        _head = new Node(T()); // T(): 用于自定义类型，内置类型也能调用"构造"
        _head->next = _head;
        _head->prev = _head;
        size = 0;
    }

    void Print()
    {
        Node *cur = _head->next;
        while (cur != _head)
        {
            std::cout << cur->val << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }

    void PushBack(const T &val)
    {
        Node* newnode = new Node(val);
        // 先修改新节点的指针
        newnode->next = _head;
        newnode->prev = _head->prev;
        // 然后再改 原链表头尾节点的指针
        _head->prev->next = newnode;
        _head->prev = newnode;
        size++;
    }

    void PushFront(const T &val)
    {
        Node* newnode = new Node(val);
        newnode->prev = _head;
        newnode->next = _head->next;
        _head->next->prev = newnode;
        _head->next = newnode;
        size++;
    }

    void PopBack()
    {
        assert(size > 0); // 确保满足这个条件
        Node* last = _head->prev; // 最后一个节点，即要删除的
        _head->prev = last->prev;
        last->prev->next = _head;
        delete last;
        size--;
    }

    void PopFront()
    {
        assert(size > 0);
        Node* frist = _head->next;
        frist->next->prev = _head;
        _head->next = frist->next;
        delete frist;
        size--;
    }

    Node* Find(const T &val)
    {
        Node* cur = _head->next;
        while(cur != _head)
        {
            if(cur->val == val)
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    // 在链表的第 pos 个位置插入节点 （下标从 0 开始）
    void Insert(const T &val, int pos)
    {
        assert(pos >= 0 && pos <= size);
        if(pos == 0)
            PushFront(val);
        else if(pos == size)
            PushBack(val);
        else
        {
            // 找到要插入的位置的前一个节点
            Node* cur = _head->next;
            for(int i = 1; i <= pos - 1; i++) // 比如要在 2 位置插入，则需要从 0 开始移动 2 - 1 步指向 1
                cur = cur->next;
            Node* newnode = new Node(val);
            newnode->prev = cur;
            newnode->next = cur->next;
            newnode->next->prev = newnode;
            newnode->prev->next = newnode;
            size++;
        }
    }

    void Erase(int pos)
    {
        assert(pos >= 0 && pos <= size - 1);
        if(pos == 0)
            PopFront();
        else if(pos == size - 1)
            PopBack();
        else
        {
            Node* cur = _head->next;
            for(int i = 1; i <= pos - 1; i++)
                cur = cur->next;
            Node* f = cur->next;
            f->next->prev = cur;
            cur->next = f->next;
            delete f;
            size--;
        }
    }

    ~BidList()
    {
        Node* cur = _head->next;
        while(cur != _head)
        {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        delete cur; // 最后 cur 指向的是 _head;
    }

private:
    Node *_head;
    int size;
};