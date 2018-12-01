#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>
#include <string>
#include "TreeNode.hpp"

class BinarySearchTree{
public:
    BinarySearchTree();
    void insert(std::string data);
    void erase(std::string data);
    void print() const;
    int count(std::string searchword) const;
private:
    TreeNode* root;
};

#endif /* BinarySearchTree_hpp */
