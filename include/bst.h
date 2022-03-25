#ifndef BST_H
#define BST_H
#include <iostream>
#include <queue>
#include <functional>
#include <map>
#include <string>
#include <iomanip>
#include <vector>
#include <initializer_list>
class BST;
class BST
{
public:
    class Node;
    Node *&get_root();
    BST();
    BST(BST &);
    //~BST();
    BST(BST &&);
    void bfs(std::function<void(Node *&node)>);
    size_t length();
    bool add_node(int);
    Node **find_node(int);
    Node **find_parrent(int);
    Node **find_successor(int);
    bool delete_node(int);
    BST &operator=(BST &);
    BST &operator=(BST &&);
    BST &operator++();
    const BST operator++(int);
    BST(int, int *[]);

private:
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
std::ostream &operator<<(std::ostream &, BST &);
#endif // BST_H