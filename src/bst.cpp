#include "bst.h"
BST::Node::Node() : value{}, right{nullptr}, left{nullptr} {};
BST::Node::Node(int _value, BST::Node *_left, BST::Node *_right) : value{_value}, left{_left}, right{_right} {};
BST::Node::Node(const BST::Node &node) : value{node.value}, left{node.left}, right{node.right} {};
std::ostream &operator<<(std::ostream &stream, const BST::Node &node)
{
    stream << "node =>\t" << &node << "\t, value :" << node.value << "\t, left:" << node.left << "\t, right:" << node.right;
    return stream;
}
bool BST::Node::operator==(const int &n) { return n == value; }
bool BST::Node::operator>(const int &n) { return n < value; }
bool BST::Node::operator<(const int &n) { return n > value; }
bool BST::Node::operator<=(const int &n) { return n >= value; }
bool BST::Node::operator>=(const int &n) { return n <= value; }

bool operator==(const int &n, const BST::Node &node) { return n == node.value; }
bool operator>(const int &n, const BST::Node &node) { return n > node.value; }
bool operator<(const int &n, const BST::Node &node) { return n < node.value; }
bool operator<=(const int &n, const BST::Node &node) { return n <= node.value; }
bool operator>=(const int &n, const BST::Node &node) { return n >= node.value; }
BST::BST() : root{nullptr} {};
bool BST::add_node(int value)
{
    if (root == nullptr)
    {
        Node *p{new Node{value, nullptr, nullptr}};
        root = p;
        return true;
    }
    Node *state{root};
    while (true)
    {
        if (value == (*state))
            break;
        else if (value > (*state))
        {
            if ((state->right) != nullptr)
                state = (state->right);
            else
            {
                Node *p{new Node{value, nullptr, nullptr}};
                (state->right) = p;
                return true;
            }
        }
        else if (value < (*state))
        {
            if ((state->left) != nullptr)
                state = (state->left);
            else
            {
                Node *p{new Node{value, nullptr, nullptr}};
                (state->left) = p;
                return true;
            }
        }
    }
    return false;
}

// BST::BST(const &BST){};
BST::Node *&BST::get_root() { return root; }