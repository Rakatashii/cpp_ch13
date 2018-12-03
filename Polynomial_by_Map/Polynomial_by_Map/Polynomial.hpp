#ifndef Polynomial_hpp
#define Polynomial_hpp

#include <stdio.h>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <sstream>

class Polynomial{
public:
    Polynomial();
    Polynomial(double coef, int deg);
    void add_term(double coef, int deg);
    
    double evaluate(double x = 1.0);
    Polynomial add(Polynomial b);
    Polynomial multiply(Polynomial b);
    void print(std::string name = "Polynomial") const;
    std::map<double, int, std::greater<int> > get_terms() { return terms; }
    int size() const { return sz; }
    
    std::string term2str(double coef, int deg) const{
        std::ostringstream oss;
        if (coef == 0.0) return "";
        else oss << coef;
        if (deg != 0.0) oss << "x\u005E" << deg;
        return oss.str();
    }
private:
    std::map<double, int, std::greater<int> > terms;
    void order();
    int sz;
};



#endif /* Polynomial_hpp */
