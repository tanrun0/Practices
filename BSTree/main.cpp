#include "BSTree.hpp"
int main()
{
    BinarySearchTree bst;

    // 测试插入
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // 测试中序遍历（应该是升序）
    std::vector<int> inorder = bst.inorderTraversal();
    assert(inorder.size() == 7);
    assert(inorder[0] == 20);
    assert(inorder[1] == 30);
    assert(inorder[2] == 40);
    assert(inorder[3] == 50);
    assert(inorder[4] == 60);
    assert(inorder[5] == 70);
    assert(inorder[6] == 80);
    std::cout << "中序遍历测试通过" << std::endl;

    // 测试查找
    assert(bst.search(50) == true);
    assert(bst.search(30) == true);
    assert(bst.search(80) == true);
    assert(bst.search(100) == false);
    std::cout << "查找测试通过" << std::endl;

    // 测试删除
    bst.remove(20); // 删除叶子节点
    inorder = bst.inorderTraversal();
    assert(inorder.size() == 6);
    assert(inorder[0] == 30);
    std::cout << "删除叶子节点测试通过" << std::endl;

    bst.remove(30); // 删除有一个子节点的节点
    inorder = bst.inorderTraversal();
    assert(inorder.size() == 5);
    assert(inorder[0] == 40);
    std::cout << "删除有一个子节点的节点测试通过" << std::endl;

    bst.remove(50); // 删除有两个子节点的节点
    inorder = bst.inorderTraversal();
    assert(inorder.size() == 4);
    assert(inorder[2] == 70);
    std::cout << "删除有两个子节点的节点测试通过" << std::endl;

    std::cout << "所有测试通过！" << std::endl;

    return 0;
}