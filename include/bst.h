#ifndef BST_H
#define BST_H
#include <iostream>
class BST;
class BST
{
public:
    class Node;
    Node *&get_root();
    BST();              /*
                  void bfs(std::function<void(Node *&node)> func);
                  size_t length();*/
    bool add_node(int); /*
     Node **find_node(int value);
     Node **find_parrent(int value);
     Node **find_successor(int value);
     bool delete_node(int value);*/

    // private:
    Node *root;
};
class BST::Node
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
std::ostream &operator<<(std::ostream &, const BST::Node &);
bool operator==(const int &, const BST::Node &);
bool operator>(const int &, const BST::Node &);
bool operator<(const int &, const BST::Node &);
bool operator<=(const int &, const BST::Node &);
bool operator>=(const int &, const BST::Node &);
#endif // BST_H