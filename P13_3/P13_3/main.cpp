/*
 Exercise P13.3.
 Implement the sieve of Eratosthenes:
 a function for computing prime numbers, known to the ancient Greeks. Choose an integer n.
 This function will compute all prime numbers up to n.
 First insert all numbers from 1 to n into a set.
 Then erase all multiples of 2 (except 2); that is, 4, 6, 8, 10, 12, .... Erase all multiples of 3, that is, 6, 9, 12, 15, ...
 Go up to n. The remaining numbers are all primes.
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

set<int> get_primes(int n);
void print_set(set<int> s, string name = "Set");

int main(int argc, const char * argv[]) {
    int n = 30;
    set<int> prime_nums = get_primes(n);
    print_set(prime_nums, "Prime Nums");
    cout << endl;
    
    return 0;
}

set<int> get_primes(int n){
    set<int> nums;
    for (int i = 1; i <= n; i++){
        nums.insert(i);
    }
    set<int>::iterator pos;
    set<int> multiples;
    bool prime;
    for (pos = nums.begin(); pos != nums.end(); /* increment handled internally */){
        prime = true;
        if (multiples.size() > 0){
            for (set<int>::iterator m = multiples.begin(); m != multiples.end(); m++){
                if (*pos % *m == 0){
                    prime = false;
                    break;
                }
            }
        }
        if (prime && *pos != 1) {
            multiples.insert(*pos);
            ++pos;
        } else pos = nums.erase(pos);
    }
    return nums;
}
void print_set(set<int> s, string name){
    cout << name << ": " << endl;
    for (set<int>::iterator pos = s.begin(); pos != s.end(); pos++){
        cout << *pos << endl;
    }
    cout << endl;
}
