/*
 Exercise P13.2. Write functions
 set<int> set_union(set<int> a, set<int> b)
 set<int> intersection(set<int> a, set<int> b)
 that compute the set union and intersection of the sets a and b. (Don’t name the first function union—that is a reserved word in C++.)
*/

#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string> set_union(set<string> a, set<string> b);
set<string> intersection(set<string> a, set<string> b);
void print_set(set<string> s, string name = "Set");

int main(int argc, const char * argv[]) {
    set<string> a;
    set<string> b;
    
    a.insert("Romeo");
    a.insert("Dave");
    a.insert("Julia");
    a.insert("Donald");
    a.insert("Chris");
    a.insert("Sara");
    
    b.insert("Lenny");
    b.insert("Mike");
    b.insert("Sara");
    b.insert("Romeo");
    b.insert("Bob");
    
    set<string> ab_union = set_union(a, b);
    print_set(ab_union, "Union");
    set<string> ab_intersection = intersection(a, b);
    print_set(ab_intersection, "Intersection");

    cout << endl;
    return 0;
}

set<string> set_union(set<string> a, set<string> b){
    set<string> u(a);
    for (set<string>::iterator pos = b.begin(); pos != b.end(); pos++){
        if (!(u.count(*pos))) u.insert(*pos);
    }
    return u;
}
set<string> intersection(set<string> a, set<string> b){
    set<string> u;
    for (set<string>::iterator apos = a.begin(); apos != a.end(); apos++){
        for (set<string>::iterator bpos = b.begin(); bpos != b.end(); bpos++){
            if (*apos == *bpos) u.insert(*apos);
        }
    }
    return u;
}
void print_set(set<string> s, string name){
    cout << name << ": " << endl;
    for (set<string>::iterator pos = s.begin(); pos != s.end(); pos++){
        cout << *pos << endl;
    }
    cout << endl;
}
