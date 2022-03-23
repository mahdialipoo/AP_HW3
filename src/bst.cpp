#include "bst.h"
Node::Node() = default;
Node::Node(int _value, Node *_left, Node *_right) : value{_value}, left{_left}, right{_right} {};
Node::Node(const Node &node) : value{node.value}, left{node.left}, right{node.right} {};
std::ostream &operator<<(std::ostream &stream, const Node &node)
{
    stream << "node =>\t" << &node << "\t, value :" << node.value << "\t, left:" << node.left << "\t, right:" << node.right;
    return stream;
}
bool Node::operator==(const int &n) { return n == value; }
bool Node::operator>(const int &n) { return n > value; }
bool Node::operator<(const int &n) { return n < value; }
bool Node::operator<=(const int &n) { return n <= value; }
bool Node::operator>=(const int &n) { return n >= value; }

bool operator==(const Node &node, const int &n) { return n == node.value; }
bool operator>(const Node &node, const int &n) { return n > node.value; }
bool operator<(const Node &node, const int &n) { return n < node.value; }
bool operator<=(const Node &node, const int &n) { return n <= node.value; }
bool operator>=(const Node &node, const int &n) { return n >= node.value; }
