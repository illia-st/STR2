#include <iostream>
#include <cstdlib>
#include "core.h"

struct Node {
    int val {};
    Node *left {nullptr}, *right {nullptr};
    Node() = default;
    Node(int key, Node* _left = nullptr, Node* _right = nullptr):
        val(key), left(_left), right(_right) {} 
};


class BSTree {
public:
    BSTree() = default;
    bool insert(int val) {
        if(root == nullptr) {
            root = new(std::nothrow) Node(val);
            if(root == nullptr) return false;
            return true;
        }
        Node* temp = find_place_to_insert(root, val);
        if(temp->val < val) {
            temp->right = new(std::nothrow) Node(val);
            return temp->right != nullptr;
        } else {
            temp->left = new(std::nothrow) Node(val);
            return temp->left != nullptr;
        }
    }
    void Inorder() {
        this->_Inorder(root);
        std::cout << std::endl;
    }
    void Preorder() {
        this->_Preorder(root);
        std::cout << std::endl;
    }
    void Postorder() {
        this->_Postorder(root);
        std::cout << std::endl;
    }
    Node* getRoot() const {
        return root;
    }
private:
    Node* find_place_to_insert(Node* node, int val) {
        if(node == nullptr) return nullptr;

        if(node->val < val) {
            auto res = find_place_to_insert(node->right, val);
            return res == nullptr ? node: res;
        }
        else {
            auto res = find_place_to_insert(node->left, val);
            return res == nullptr ? node: res;
        }
    }
    void _Inorder(Node* node) {
        if(node == nullptr) return;
        _Inorder(node->left);
        std::cout << node->val << " ";
        _Inorder(node->right);
    }
    void _Preorder(Node* node) {
        if(node == nullptr) return;
        std::cout << node->val << " ";
        _Preorder(node->left);
        _Preorder(node->right);
    }
    void _Postorder(Node* node) {
        if(node == nullptr) return;
        _Postorder(node->left);
        _Postorder(node->right);
        std::cout << node->val << " ";
    }
    Node* root {nullptr};
};
int COUNT = 10;
void print2DUtil(Node* root, int space=0)
{
    if (root == nullptr)
        return;
 
    space += COUNT;
 
    print2DUtil(root->right, space);
 
    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << root->val << "\n";

    print2DUtil(root->left, space);
}

int main() {
    auto values = generate_random_sequence(10, 1, 100);
    BSTree tree;
    for(auto val: values) {
        tree.insert(val); 
    }
    print2DUtil(tree.getRoot());
    std::cout << "Inorder" << std::endl;
    tree.Inorder();
    std::cout << "Postorder" << std::endl;
    tree.Postorder();
    std::cout << "Preorder" << std::endl;
    tree.Preorder(); 
    return 0;
}