/*
 Exercise P13.1.
 Reimplement the Polynomial class of Exercise P12.14 by using a map<int, double> to store the coefficients.
*/

#include <iostream>
#include <map>
#include <string>
#include "Polynomial.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    string poly = "5.5x^5 - 4.4x^4 + 3.3x^3 - 2.2x^2 + 1.1x - 50.50";
    map<double, int, std::greater<int> > p1terms; // maps are sorted by value, not key (even if type for #greater was double this wouldn't change)
    
    p1terms[5.5] = 5;
    p1terms[-4.4] = 4;
    p1terms[3.3] = 3;
    p1terms[-2.2] = 2;
    p1terms[-50.50] = 0;
    
    map<double, int>::iterator start = p1terms.begin();
    map<double, int>::iterator stop = p1terms.end();
    for(map<double, int>::iterator pos = start; pos != stop; pos++){
        if (pos == p1terms.begin()){
            printf("%2.2fx^%i", pos->first, pos->second);
        } else if (pos->first > 0){
            printf(" + %2.2fx^%i", pos->first, pos->second);
        } else if (pos->first < 0){
            double positive_first = -1 * pos->first;
            printf(" - (%2.2fx^%i)", positive_first, pos->second);
        }
    }
    cout << endl;
    
    Polynomial p;
    p.add_term(5.5, 5);
    p.add_term(-4.4, 4);
    p.add_term(3.3, 3);
    p.add_term(-2.2, 2);
    p.add_term(-50.50, 0);
    p.print();
    
    double result;
    int x = 1.0;
    result = p.evaluate(x);
    cout << "result = " << result << endl;
    x = 2.0;
    result = p.evaluate(x);
    cout << "result = " << result << endl;
    cout << "comp to: " << ((5.5*pow(x, 5)) + (-4.4*pow(x, 4) + (3.3*pow(x, 3)) + (-2.2*pow(x, 2)) - 50.50)) << endl; // good
    Polynomial b(10, 1);
    p.add(b);
    
    
    
    cout << endl;
    return 0;
}
