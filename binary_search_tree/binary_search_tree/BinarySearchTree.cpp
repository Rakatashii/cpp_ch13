#include "BinarySearchTree.hpp"

BinarySearchTree::BinarySearchTree(){
    root = NULL;
}
void BinarySearchTree::insert(std::string data){
    TreeNode* new_node = new TreeNode;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    if (root == NULL) {
        root = new_node;
    }
    else root->insert_node(new_node);
}
void BinarySearchTree::erase(std::string data){
    TreeNode* to_be_removed = root;
    TreeNode* parent = NULL;
    bool found = false;
    
    while (!found && to_be_removed != NULL){
        if (data > to_be_removed->data){
            parent = to_be_removed;
            to_be_removed = parent->right;
        } else found = true;
        if (data < to_be_removed->data){
            parent = to_be_removed;
            to_be_removed = parent->left;
        } else found = true;
    }
    if (!found) return;
    
    // Case: 0 or 1 child of to_be_removed
    if (to_be_removed->left == NULL || to_be_removed->right == NULL){
        TreeNode* new_child;
        if (to_be_removed->left == NULL){
            new_child = to_be_removed->right;
        } else { // tbr->right == NULL
            new_child = to_be_removed->left;
        }
        if (parent == NULL){ // parent should not be null unless the erased value is the root itself, since parent wouldn't have changed and tbr == root
            root = new_child;
        }
        else if (parent->left == to_be_removed){
            parent->left = new_child;
        } else parent->right = new_child;
        return;
    }
    
    // Case: to_be_removed has two children
    TreeNode* smallest_parent = to_be_removed;
    TreeNode* smallest = to_be_removed->right;
    while (smallest->left != NULL){
        smallest_parent = smallest;
        smallest = smallest->left;
    }
    
    to_be_removed->data = smallest->data;
    if (to_be_removed == smallest_parent)
        smallest_parent->right = smallest->right;
    else
        smallest_parent->left = smallest->right;
}

void BinarySearchTree::print() const{
    if (root != NULL) root->print_nodes();
}

int BinarySearchTree::count(std::string searchword) const{
    if (root == NULL) return 0;
    else if (root->find(searchword)) return 1;
    else return 0;
}
