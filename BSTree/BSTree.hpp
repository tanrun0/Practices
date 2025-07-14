#include <iostream>
#include <vector>
#include <cassert>

// 二叉搜索树节点定义
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
    TreeNode *root;

    // 辅助函数：插入节点
    TreeNode *insert(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return new TreeNode(val);
        }
        if (val < node->val)
        {
            node->left = insert(node->left, val);
        }
        else
        {
            node->right = insert(node->right, val);
        }
        return node;
    }

    // 辅助函数：查找节点
    bool search(TreeNode *node, int val) const
    {
        if (node == nullptr)
        {
            return false;
        }
        if (val == node->val)
        {
            return true;
        }
        else if (val < node->val)
        {
            return search(node->left, val);
        }
        else
        {
            return search(node->right, val);
        }
    }

    // 辅助函数：查找最小节点
    TreeNode *findMin(TreeNode *node) const
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    // 辅助函数：删除节点
    TreeNode *remove(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return node;
        }
        if (val < node->val)
        {
            node->left = remove(node->left, val);
        }
        else if (val > node->val)
        {
            node->right = remove(node->right, val);
        }
        else
        {
            // 情况1: 没有子节点或只有一个子节点
            if (node->left == nullptr)
            {
                TreeNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                TreeNode *temp = node->left;
                delete node;
                return temp;
            }
            // 情况2: 有两个子节点
            TreeNode *temp = findMin(node->right);
            node->val = temp->val;
            node->right = remove(node->right, temp->val);
        }
        return node;
    }

    // 辅助函数：中序遍历
    void inorder(TreeNode *node, std::vector<int> &result) const
    {
        if (node != nullptr)
        {
            inorder(node->left, result);
            result.push_back(node->val);
            inorder(node->right, result);
        }
    }

    // 辅助函数：销毁树
    void destroyTree(TreeNode *node)
    {
        if (node != nullptr)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    // 构造函数
    BinarySearchTree() : root(nullptr) {}

    // 析构函数
    ~BinarySearchTree()
    {
        destroyTree(root);
    }

    // 插入节点
    void insert(int val)
    {
        root = insert(root, val);
    }

    // 查找节点
    bool search(int val) const
    {
        return search(root, val);
    }

    // 删除节点
    void remove(int val)
    {
        root = remove(root, val);
    }

    // 获取中序遍历结果
    std::vector<int> inorderTraversal() const
    {
        std::vector<int> result;
        inorder(root, result);
        return result;
    }
};