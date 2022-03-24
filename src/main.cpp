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
        bst.add_node(53);
        bst.add_node(57);
        bst.add_node(46);
        std::vector<int> values;
        bst.bfs([&values](BST::Node *&node)
                { values.push_back(node->value); });
        //  debug section
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