//
// Created by Asus on 21.09.2016.
//
#include <iostream>
#include <fstream>



template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree() : root_(nullptr), size_(0) {};

    BinarySearchTree(const std::initializer_list<T>& list) : BinarySearchTree()
    {
        for (auto& value : list)
            insert(value);
    };

    ~BinarySearchTree()
    {
        delete root_;
        size_ = 0;
    }

    auto size() const noexcept -> size_t
    {
        return size_;
    };

    auto insert(const T& value) noexcept -> bool
    {
        if (size_ == 0)
        {
            root_ = new Node(value);
            size_ = 1;
            return true;
        }
        Node* curNode = root_;
        Node* prevNode = nullptr;
        while (curNode)
        {
            prevNode = curNode;
            if (value == curNode->value_) return false;
            else if (value < curNode->value_) curNode = curNode->left_;
            else curNode = curNode->right_;
        }
        if (value < prevNode->value_)
            prevNode->left_ = new Node(value);
        else
            prevNode->right_ = new Node(value);
        size_++;
        return true;
    }

    auto find(const T& value) const noexcept -> const T*
    {
        if (size_ == 0) return nullptr;
        Node* curNode = root_;
        do
        {
            if (value == curNode->value_) return &curNode->value_;
            else if (value < curNode->value_) curNode = curNode->left_;
            else if (value > curNode->value_) curNode = curNode->right_;
        } while (curNode);
        return nullptr;
    }

    BinarySearchTree(const BinarySearchTree& tree)
    {
        size_=tree.size_;
        root_=tree.root_->copy();
    }

    BinarySearchTree(BinarySearchTree&& tree)
    {
       root_= tree.root_;
        tree.root_=nullptr;
        size_=tree.size_;
        tree.size_= nullptr;
    }

    auto operator == (const BinarySearchTree& tree) const -> bool
    {
        if (this == &tree) return true;
        else if (size_ == tree.size_) return tree.equal(root_, tree.root_);
        else return false;
    }

    auto operator = (const BinarySearchTree& tree) -> BinarySearchTree&
    {
        if (this == &tree) return *this;
        else
        {
            delete root_;
            size_ = tree.size_;
            root_ = tree.root_->copy();
            return *this;
        }
    }

    auto operator = (BinarySearchTree&& tree) -> BinarySearchTree&
    {
        if (this == &tree) return *this;
        else
        {
            delete root_;
            size_ = tree.size_;
            tree.size_ = 0;
            root_ = tree.root_;
            tree.root_ = nullptr;
            return *this;
        }
    }

    friend  auto operator<<(std::ostream& out, const BinarySearchTree<T>& tree)->std::ostream&
    {
        tree.oright(out, tree.root_);
        return out;
    }

    friend  auto operator<<(std::ofstream& out, const BinarySearchTree<T>& tree)->std::ofstream&
    {
        tree.oleft(out, tree.root_);
        return out;
    }

    friend std::istream& operator>>(std::istream& in, BinarySearchTree<T>& tree)
    {
        T value;
        while (in >> value) tree.insert(value);
        return in;
    }

private:
    struct Node
    {
        Node * left_;
        Node * right_;
        T value_;
        Node(): left_(nullptr), right_(nullptr){}
        Node(T value) : value_(value), left_(nullptr), right_(nullptr) {}

    Node* copy()
            {
               Node* node = new Node(value_);
                if (right_)
                    node->right_=right_->copy();
                if (left_)
                    node->left_=left_->copy();
                return node;
            };

       /* friend std::ostream& operator<<(std::ostream& out, const Node& node)
        {
            out << node.value_ << ' ';
            if (node.left_) out << *node.left_;
            if (node.right_) out << *node.right_;
            return out;
        }*/
        ~Node()
        {
            if (left_)
                delete left_;
            if (right_)
                delete right_;
        }
    };

    Node* root_;
    size_t size_;

bool oleft(std::ostream& out, Node* node) const noexcept
{
    if(node)
    {
        oleft(out, node->right_);
        out << node->value_ << ' ';
        oleft(out, node->left_);
        return true;
    } else return false;
}

bool oright(std::ostream& out, Node* node) const noexcept
{
    if(node)
    {
        out << node->value_ << ' ';
        oright(out, node->left_);
        oright(out, node->right_);
        return true;
    } else return false;
}

    bool equal(Node* fnode, Node* snode) const noexcept
    {
        if (fnode)
            return snode && (fnode->value_ == snode->value_) &&
                   equal(fnode->left_, snode->left_) &&
                   equal(fnode->right_, snode->right_);
        else return !snode;
    }
};
