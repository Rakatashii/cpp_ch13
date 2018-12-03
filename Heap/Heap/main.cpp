#include <iostream>
#include <cmath>
#include "heap.hpp"

using namespace std;

// downleft arrow \u2199
// downright arrow \u2198

int main(int argc, const char * argv[]) {
    cout << "floor(log2(15))+1 = " << floor(log2(8))+1 << endl;
    cout << "floor(log2(15))+1 = " << floor(log2(15))+1 << endl;
    cout << "floor(log2(15))+1 = " << floor(log2(15))+1 << endl;
    cout << endl;
    
    Heap H;
    H.push(18);
    H.push(17);
    H.push(5); // last top in loop
    H.push(32);
    H.push(15);
    H.push(41); // first top in loop
    H.push(8);
    
    int prev_size = H.size();
    for (int i = 0; i < prev_size; i++){
        cout << "H.size() = " << H.size() << endl;
        cout << "H.top() = " << H.top() << endl;
        H.pop();
        cout << endl;
    }
    
    cout << endl;
    return 0;
}
