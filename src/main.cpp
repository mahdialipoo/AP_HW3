#include <iostream>
#include <gtest/gtest.h>
#include "bst.h"

int main(int argc, char **argv)
{
    if (0) // make false to run unit-tests
    {
        BST bst{1, 2, 3};

        // BST bst{1, 2, 3, 6, 7, 8, 9, 10};
        std::cout << bst << std::endl;
        //    bst.delete_node(25);
        //    std::cout << bst.length() << std::endl;
        //    std::cout << bst.get_root()->left->left->right->value << std::endl;
        //      debug section
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