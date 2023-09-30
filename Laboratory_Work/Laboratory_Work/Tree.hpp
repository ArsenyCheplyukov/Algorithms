#include <iostream>

int current_level = 1;

template <typename T> 
class Tree 
{
public:
    struct Node
    {
        T key_value;
        Node* left;
        Node* right;
    };
private:
    Node* top_;
public:
    Tree ()
    : top_(nullptr)
    {

    }

    Tree (const Tree& rhs) 
    {
        
    }

    Tree(const T value)
    {
        top_->key_value = value;
    }

    virtual ~Tree()
    {
        Delete_();
    }

    Node* Search(const T& d)
    {
       Node* pv = top_, *ppv = top_;
        while (pv) {
            ppv = pv;
            if (d < pv->key_value) {
                pv = pv->left;
            }
            else {
                pv = pv->right;
            }
        }
        return ppv;
    }

    Node* Find(const T &d)
    {
        if (!top_) {
            return NULL;
        }
        Node* some_node;
        if (d < top_->key_value) {
            some_node = Find(top_->left, d);
        }
        else {
            some_node = Find(top_->right, d);
        }
        return some_node ? some_node : top_;
    }

    void Add(const T& d)
    {
        if (!top_) {
            top_ = new Node();
            top_->key_value = d;
            top_->left = nullptr;
            top_->right = nullptr;
        }
        else {
            Node* ppv = Search(d);
            // ppv = find(top_, d); // and simmilar 
            // but with recursion
            if (d < ppv->key_value) {
                Node new_node = new Node();
                ppv->left = *new_node;
                new_node->key_value = d;
            }
            //adding to left piece of previous tree
            else {
                Node new_node = new Node();
                ppv->right = *new_node;
                new_node->key_value = d;
            }
            //adding to right piece of previous tree
        }
    }

    void Print()
    {
        if (top_) {
            //going to left part of a tree
            Print(top_->left);
            std::cout << top_->key_value << " ";
            //going to right part of a tree
            Print(top_->right);
        }
    }

    void PrintLevel(const int& level)
    {
        if (top_) {
            PrintLevel(top_->left, level + 1);
            // going to left part of a tree
            for (int i = 0; i < level; i++) {
                std::cout << " ";
            }
            std::cout << top_->key_value << std::endl;
            // going to right part of tree
            PrintLevel(top_->right, level + 1);
        }
    }

    void Copy(const Node*& top1)
    {
        if (top1)
        {
            //adding new part to a tree
            Add(top1->key_value);
            //going to left piece of tree
            Copy(top1->left);
            //going to right piece of tree
            Copy(top1->right); 
        }
    }

    int Size(const Node*& node)
    {
        if (node == nullptr) {
            return 0;
        }
        else {
            return(Size(node->left) + 1 + Size(node->right));
        }
    }

    int MaxDepth()
    {
        if (top_ == NULL) {
            return 0;
        }
        else {
            // compute the depth of each subtree
            int lDepth = MaxDepth(top_->left);
            int rDepth = MaxDepth(top_->right);

            // use the larger one 
            if (lDepth > rDepth) {
                return(lDepth + 1);
            }
            else {
                return(rDepth + 1);
            }
        }
    }

    void ShowPatch(const Tree*& tree, const T& key)
    {
        if (tree == NULL) {
            return 0;
        }
        if (key == tree->key_value) {
            std::cout << tree->key_value << " ";
            return current_level;
        }
        else if (key > tree->key_value) {
            std::cout << tree->key_value << " ";
            ShowPatch(tree->right, key);
        }
        else if (key < tree->key_value) {
            std::cout << tree->key_value << " ";
            ShowPatch(tree->left, key);
        }
        else {
            std::cout << "This value doesn't exist\n";
        }
    }

    private:
    void Delete_()
    {
        if (top_) {
            //going to left piece of node
            Delete_(top_->left);
            //going to right
            Delete_(top_->right);
            delete top_;
            top_ = NULL;
            //cleaning memory
        }
    }
};
