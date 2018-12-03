#ifndef heap_hpp
#define heap_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>

class Heap{
public:
    Heap();
    void push(int new_elem);
    int top() const;
    void pop();
    int size() const;
    
    int operator[](int index) const { return elements[index]; }
    void display() const;
private:
    void fix_heap();
    
    int get_left_child_index(int index); // parameter is index of parent node
    int get_right_child_index(int index);
    int get_parent_index(int index);
    
    int get_left_child(int index); // returns value, not arr/vect index
    int get_right_child(int index);
    int get_parent(int index);
    
    std::vector<int> elements;
};

#endif /* heap_hpp */
