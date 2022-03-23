#ifndef BST_H
#define BST_H
#include <iostream>
class Node
{
public:
    Node(int, Node *, Node *);
    Node();
    Node(const Node &);
    int value;
    Node *left;
    Node *right;
    bool operator==(const int &);
    bool operator>(const int &);
    bool operator<(const int &);
    bool operator>=(const int &);
    bool operator<=(const int &);
};
std::ostream &operator<<(std::ostream &, const Node &);
bool operator==(const Node &, const int &);
bool operator>(const Node &, const int &);
bool operator<(const Node &, const int &);
bool operator<=(const Node &, const int &);
bool operator>=(const Node &, const int &);
#endif // BST_H