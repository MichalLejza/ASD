#include "BSTree.cpp"
#include "AVLTree.cpp"
#include "/Users/michallejza/CLionProjects/Everything/Algorytmy/PrintBT.hpp"

void testBSTTree()
{
    auto *tree = new Tree::BSTree<int>();
    tree -> insert(8,4,2,1,3,6,5,7,12,10,9,11,14,13,16, 17, 15);
    print(tree);
}

void testAVLTree()
{
    auto *tree = new Tree::AVLTree<int>();
    tree -> insert(11,14,18,13,1,9,17,10,15,12);
    print(tree);
    tree ->removeNode(12);
    print(tree);
    tree ->removeNode(14);
    print(tree);
    tree ->removeNode(13);
    print(tree);
}

auto main() -> int
{
    //testBSTTree();
    testAVLTree();
    return 0;
}
