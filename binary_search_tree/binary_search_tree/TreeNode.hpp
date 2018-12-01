#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>
#include <iostream>
#include <string>

class BinarySearchTree;

class TreeNode{
public:
    TreeNode();
    TreeNode(std::string d);
    void insert_node(TreeNode* new_node);
    void print_nodes() const;
    bool find(std::string searchword) const;
private:
    std::string data;
    //TreeNode* parent; // This is tracked by root, the original parent, and left can be the parents of further lefts, etc.
    TreeNode* left;
    TreeNode* right;
    
    friend class BinarySearchTree;
};

#endif /* TreeNode_hpp */
