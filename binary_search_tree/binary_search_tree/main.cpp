#include <iostream>
#include "BinarySearchTree.hpp"
#include <map>
#include <string>
#include <utility>

using namespace std;

int main(int argc, const char * argv[]) {
    BinarySearchTree tree;
    tree.insert("Hanah");
    tree.insert("Trump");
    tree.insert("Donald");
    tree.insert("Gary");
    tree.erase("Donald");
    
    tree.print();
    cout << endl;
    
    int found1 = tree.count("Hanah");
    int found2 = tree.count("Trump");
    int found3 = tree.count("Donald");
    int found4 = tree.count("Gary");
    cout << "found \"Hanah\" = " << found1 << endl;
    cout << "found \"Trump\" = " << found2 << endl;
    cout << "found \"Donald\" = " << found3 << endl;
    cout << "found \"Gary\" = " << found4 << endl;
    cout << endl;
    
    map<string, double> m;
    m["Tom"] = 9.0;
    m["gary"] = 6.6;
    m["Larry"] = 5.0;
    cout << "m[\"Tom\"] = " << m["Tom"] << endl;
    map<string, double>::iterator pos = m.find("Tom");
    cout << "pos->first = " << pos->first << " | pos->second = " << pos->second << endl;
    cout << endl;
    
    multimap<string, string> friendlist;
    friendlist.insert(make_pair("Hank", "Spank"));
    friendlist.insert(make_pair("Hank", "Shank"));
    friendlist.insert(make_pair("Hank", "Pank"));
    friendlist.insert(make_pair("Hank", "Shlank"));
    
    multimap<string, string>::iterator lower = friendlist.lower_bound("Hank");
    multimap<string, string>::iterator upper = friendlist.upper_bound("Hank");
    multimap<string, string>::iterator last = upper; --last;
    for (multimap<string, string>::iterator pos = lower; pos != upper; pos++){
        cout << pos->second << " is a friend of " << pos->first << endl;
        if (pos == last) friendlist.erase(pos);
    }
    cout << endl;
    upper = friendlist.upper_bound("Hank"); // erased "Shlank"
    for (multimap<string, string>::iterator pos = lower; pos != upper; pos++){
        cout << pos->second << " is a friend of " << pos->first << endl;
    }
    cout << endl;
    
    cout << endl;
    return 0;
}
