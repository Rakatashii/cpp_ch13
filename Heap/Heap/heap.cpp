#include "heap.hpp"

// ****** PUBLIC ******
Heap::Heap(){
    elements.push_back(0);
}
void Heap::push(int new_element){
    // Add new leaf
    elements.push_back(0); // new node - dummy value
    int index = elements.size() - 1;
    while (index > 1 && get_parent(index) < new_element){
        elements[index] = get_parent(index);
        index = get_parent_index(index);
    }
    elements[index] = new_element;
}
int Heap::top() const{
    return elements[1];
}
void Heap::pop(){
    int last_index = size();
    int last = elements[last_index]; // new root value
    elements.pop_back(); // remove the last elements so there is not a duplicate
    if (last_index > 1){
        elements[1] = last; // Remove root by setting a new root to value of the last element
        fix_heap(); // Restore heirarchy
    }
}
int Heap::size() const{
    return elements.size() - 1; // -1 not for convenience, but b/c dummy val pushed back in constructor
}
/*
void Heap::display() const{
    int sz = elements.size()-1;
    int layers = log2(sz)+1;
    if (layers == pow(2, log2(sz))) sz++;
    layers = log2(sz)+1;
    int max_elements_per_layer = pow(2, layers-1);
    int half_width = (max_elements_per_layer * 3) / 2;
    
    auto downleft = '/';
    auto downright = '\\';
    std::string spaces(10, ' ');
    std::cout << spaces << '|' << std::endl;
    for (int i = 1; i <= size(); i++){
        int current_layer = 0;
        int elements_per_layer = pow(2, current_layer);
        int half_width = half_width / current_layer;
        std::string top;
        std::string bottom;
        std::ostringstream oss_top;
        std::ostringstream oss_bot;
        for (int j = i; j < (i+elements_per_layer); j++){
            oss_top.str("");
            oss_bot.str("");
            oss_top << std::string(half_width, ' ') << " " << elements[i] << " " << std::string(half_width, ' ');
            oss_bot << std::string(half_width, ' ') << downleft << " " << downright << std::string(half_width, ' ');

            std::cout << oss_top.str() << std::endl;
            std::cout << oss_bot.str() << std::endl;
        }
        current_layer++;
    }
}
 */

// ****** PRIVATE ******
void Heap::fix_heap(){
    int root = elements[1]; // assumes elements[1] has already been set to value of last node
    int last_index = size();
    
    int index = 1;
    bool more = true;
    
    while(more){
        int child_index = get_left_child_index(index);
        if (child_index <= last_index){
            int child = get_left_child(index);
            if (get_right_child_index(index) <= last_index && get_right_child(index) > child){
                child_index = get_right_child_index(index);
                child = get_right_child(index);
            }
            if (child > root){
                // promote child
                elements[index] = child;
                index = child_index; // the child is made parent, and we keep track of index so the original root can be placed at this child's previous location if true
            }
            else {
                // root is larger than either child
                more = false;
            }
        } else {
            more = false; // there is no index past the child index, so child must not have children
        }
    }
    elements[index] = root;
}
int Heap::get_left_child_index(int index){ // parameter is index of parent node
    return 2 * index;
}
int Heap::get_right_child_index(int index){
    return 2 * index + 1;
}
int Heap::get_parent_index(int index){
    return index / 2;
}
int Heap::get_left_child(int index){ // returns value, not arr/vect index
    return elements[get_left_child_index(index)];
}
int Heap::get_right_child(int index){
    return elements[get_right_child_index(index)];
}
int Heap::get_parent(int index){
    return elements[get_parent_index(index)];
}
