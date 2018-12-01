#include "TreeNode.hpp"

TreeNode::TreeNode(){
    left = NULL;
    right = NULL;
}
TreeNode::TreeNode(std::string d){
    data = d;
    left = NULL;
    right = NULL;
}
void TreeNode::insert_node(TreeNode* new_node){
    if (new_node->data < data){
        if (left == NULL) left = new_node;
        else left->insert_node(new_node);
    }
    else if (new_node->data > data){
        if (right == NULL) right = new_node;
        else right->insert_node(new_node);
    }
}
void TreeNode::print_nodes() const{
    if (left != NULL)
        left->print_nodes();
    std::cout << data << std::endl;
    if (right != NULL)
        right->print_nodes();
}

bool TreeNode::find(std::string searchword) const{
    if (searchword < data){
        if (left == NULL) return false;
        else return left->find(searchword);
    } else if (searchword > data){
        if (right == NULL) return false;
        else return right->find(searchword);
    } else return true;
}
