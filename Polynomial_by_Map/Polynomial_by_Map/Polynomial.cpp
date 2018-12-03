#include "Polynomial.hpp"

// public:
Polynomial::Polynomial(){ sz = 0; }
Polynomial::Polynomial(double coef, int deg){
    terms[coef] = deg;
    sz = 1;
}
void Polynomial::add_term(double coef, int deg){
    terms[coef] = deg;
    sz++;
}
double Polynomial::evaluate(double x){
    std::map<double, int, std::greater<int> >::iterator start = terms.begin();
    std::map<double, int, std::greater<int> >::iterator stop = terms.end();
    double sol = 0.0;
    for (std::map<double, int, std::greater<int> >::iterator pos = start; pos != stop; pos++){
        sol += pos->first * pow(x, pos->second);
    }
    return sol;
}
Polynomial Polynomial::add(Polynomial b){
    Polynomial result = *this;
    std::map<double, int, std::greater<int> >::iterator a_start = terms.begin();
    std::map<double, int, std::greater<int> >::iterator a_stop = terms.end();
    std::map<double, int, std::greater<int> > bterms = b.get_terms();
    std::map<double, int, std::greater<int> >::iterator b_start = bterms.begin();
    std::map<double, int, std::greater<int> >::iterator b_stop = bterms.end();
    
    for (std::map<double, int, std::greater<int> >::iterator bpos = b_start; bpos != b_stop; bpos++){
        bool match = false;
        for (std::map<double, int, std::greater<int> >::iterator apos = a_start; apos != a_stop; apos++){
            if (apos->second == bpos->second){
                match = true;
                result.add_term(apos->first+bpos->first, apos->second);
            }
        }
        if (!match){
            result.add_term(bpos->first, bpos->second);
        }
    }
    return result;

}

Polynomial Polynomial::multiply(Polynomial b){
    Polynomial result = *this;
    std::map<double, int, std::greater<int> >::const_iterator a_start = terms.begin();
    std::map<double, int, std::greater<int> >::const_iterator a_stop = terms.end();
    std::map<double, int, std::greater<int> > bterms = b.get_terms();
    std::map<double, int, std::greater<int> >::const_iterator b_start = bterms.begin();
    std::map<double, int, std::greater<int> >::const_iterator b_stop = bterms.end();
    
    for (std::map<double, int, std::greater<int> >::const_iterator bpos = b_start; bpos != b_stop; bpos++){
        bool match = false;
        for (std::map<double, int, std::greater<int> >::const_iterator apos = a_start; apos != a_stop; apos++){
            if (apos->second == bpos->second){
                match = true;
                result.add_term(apos->first*bpos->first, apos->second+bpos->second);
            }
        }
 
        if (!match){
            result.add_term(bpos->first, bpos->second);
        }
 
    }
    return result;
}

void Polynomial::print(std::string name) const{
    std::string poly_str;
    std::map<double, int, std::greater<int> >::const_iterator start = terms.begin();
    std::map<double, int, std::greater<int> >::const_iterator stop = terms.end();
    std::cout << name << ": ";
    for (std::map<double, int, std::greater<int> >::const_iterator iter = start; iter != stop; iter++){
        if (iter->first > 0.0) {
            if (iter->first != start->first) poly_str += " + ";
            poly_str += term2str(iter->first, iter->second);
        }
        else if (iter->first < 0.0) {
            if (iter->first != start->first) poly_str += " - ";
            if (iter->second != 0){
                poly_str += "(" + term2str(iter->first, iter->second).substr(1) + ")";
            } else poly_str += term2str(iter->first, iter->second).substr(1);
        }
    }
    std::cout << poly_str << std::endl;
}

// private:
/*
std::map<double, int, std::greater<int> > terms;
void order();
*/
