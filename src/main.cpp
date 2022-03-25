#include <iostream>
#include <gtest/gtest.h>
#include "bst.h"

int main(int argc, char **argv)
{
    if (0) // make false to run unit-tests
    {
        BST bst{};
        bst.add_node(25);
        bst.add_node(10);
        bst.add_node(50);
        bst.add_node(65);
        bst.add_node(60);
        bst.add_node(70);
        bst.add_node(5);
        bst.add_node(2);
        bst.add_node(7);
        bst.add_node(75);
        bst.add_node(20);
        bst.add_node(15);
        bst.add_node(22);
        std::cout << (*bst.find_parrent((*bst.find_successor(25))->value))->value << std::endl;
        std::cout << bst.length() << std::endl;
        bst.delete_node(25);
        std::cout << bst.length() << std::endl;
        // std::cout << bst.get_root()->left->left->right->value << std::endl;
        //   debug section
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}