#include "bst.h"
BST::Node::Node() : value{}, right{nullptr}, left{nullptr} {};
BST::Node::Node(int _value, BST::Node *_left, BST::Node *_right) : value{_value}, left{_left}, right{_right} {};
BST::Node::Node(const BST::Node &node) : value{node.value}, left{node.left}, right{node.right} {};
std::ostream &operator<<(std::ostream &stream, const BST::Node &node)
{
    stream << &node << "\t=>"
           << " value :" << std::setw(10) << std::left << node.value << "left:" << std::setw(10) << std::left << node.left << "    right:" << std::setw(10) << std::left << node.right;
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

BST::Node *&BST::get_root()
{
    Node *&v{root};
    return v;
}
void BST::bfs(std::function<void(BST::Node *&node)> func)
{
    if (root)
    {
        std::map<Node *, bool> mark;
        std::queue<Node *> q;
        Node *state{root};
        mark[state] = true;
        q.push(state);
        while (q.size())
        {
            state = q.front();
            func(state);
            q.pop();
            if ((!mark[state->left]) && (state->left != nullptr))
            {
                mark[state->left] = 1;
                q.push(state->left);
            }
            if ((!mark[state->right]) && (state->right != nullptr))
            {
                mark[state->right] = 1;
                q.push(state->right);
            }
        }
    }
}
size_t BST::length()
{
    if (!root)
        return 0;
    size_t t{};
    bfs([&t](BST::Node *&node)
        { t++; });
    return t;
}
std::ostream &operator<<(std::ostream &stream, BST &bst)
{
    stream << std::string(76, '*') << std::endl;
    bst.bfs([&stream](BST::Node *&node)
            { stream << *node << std::endl; });
    stream << "binary search tree size: " << bst.length() << std::endl;
    stream << std::string(76, '*') << std::endl;

    return stream;
}

BST::Node **BST::find_node(int value)
{
    Node **state{&root};
    while (true)
    {
        if (value == (**state))
            return state;
        else if (value > (**state) && ((*state)->right) != nullptr)
            state = &((*state)->right);

        else if (value < (**state) && ((*state)->left) != nullptr)
            state = &((*state)->left);
        else
            return nullptr;
    }
    return nullptr;
}
BST::Node **BST::find_parrent(int value)
{
    Node **state{&root};
    while (true)
    {
        if (((((*state)->left) != nullptr) && value == (*(*state)->left)) || ((((*state)->right) != nullptr) && value == (*(*state)->right)))
            return state;
        else if ((((*state)->right) != nullptr) && value > **state)
            state = &((*state)->right);
        else if (((*state)->left) != nullptr && value < **state)
            state = &((*state)->left);
        else
            return nullptr;
    }
    return nullptr;
}
BST::Node **BST::find_successor(int value)
{
    Node **state{find_node(value)};
    if ((*state)->left == nullptr)
        state = &((*state)->right);
    else
        state = &((*state)->left);
    while (true)
    {
        if ((*state)->left == nullptr && (*state)->right == nullptr)
            return state;
        else if ((*state)->right == nullptr)
            state = &((*state)->left);

        else if ((*state)->right != nullptr)
            state = &((*state)->right);
        else
            return nullptr;
    }
    return nullptr;
}
BST::~BST()
{
    if (!root)
    {
        std::vector<Node *> nodes;
        bfs([&nodes](BST::Node *&node)
            { nodes.push_back(node); });
        for (auto &node : nodes)
            delete node;
    }
}

bool BST::delete_node(int value)
{
    if (find_node(value) == nullptr)
        return false;
    Node *v{*find_node(value)};
    Node *pr{};
    if (find_parrent(value) != nullptr)
        pr = *find_parrent(value);
    if (v->right == nullptr && v->left == nullptr)
    {
        if (pr != nullptr)
            if (pr->value > *v)
                pr->left = nullptr;
            else
                pr->right = nullptr;
    }
    else if (v->right != nullptr && v->left == nullptr)
    {
        if (pr != nullptr)
            if (pr->value > *v)
                pr->left = v->right;
            else
                pr->right = v->right;
    }
    else if (v->right == nullptr && v->left != nullptr)
    {
        if (pr != nullptr)
            if (pr->value > *v)
                pr->left = v->left;
            else
                pr->right = v->left;
    }
    else
    {
        Node *ps{*find_successor(value)};
        ps->left = v->left;
        ps->right = v->right;
        Node *pspr{(*find_parrent(ps->value))};
        if (pspr->value > ps->value)
            pspr->left = nullptr;
        else
            pspr->right = nullptr;
        if (pr != nullptr)
            if (pr->value > *v)
                pr->left = ps;
            else
                pr->right = ps;
        else
            root = ps;
    }
    delete v;
    return true;
}
BST::BST(BST &bst) : BST::BST()
{
    bst.bfs([this](BST::Node *&node)
            { add_node(node->value); });
}
BST &BST::operator=(BST &bst)
{
    if (root == bst.get_root())
        return *this;
    std::vector<Node *> nodes;
    bfs([&nodes](BST::Node *&node)
        { nodes.push_back(node); });
    for (auto &node : nodes)
        delete node;
    bst.bfs([this](BST::Node *&node)
            { add_node(node->value); });
    return *this;
}
BST::BST(BST &&bst)
{
    root = bst.get_root();
}
BST &BST::operator=(BST &&bst)
{
    std::vector<Node *> nodes;
    bfs([&nodes](BST::Node *&node)
        { nodes.push_back(node); });
    for (auto &node : nodes)
        delete node;
    root = &*bst.get_root();
    return *this;
}
BST::BST(std::initializer_list<int> mList) : BST::BST()
{
    for (auto i : mList)
        add_node(i);
}
BST &BST::operator++()
{
    bfs([](BST::Node *&node)
        { ++node->value; });
    return *this;
}
BST BST::operator++(int)
{
    auto copy{*this};
    ++(*this);
    return copy;
}
