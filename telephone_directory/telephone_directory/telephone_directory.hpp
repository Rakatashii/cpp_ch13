#ifndef telephone_directory_hpp
#define telephone_directory_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <vector>

class TelephoneDirectory{
public:
    void add_entry(std::string n, long int tele);
    long int find_entry(std::string n);
    std::vector<std::string> find_entries(long int tele);
    void print_all();
private:
    std::map<std::string, long int> db;
    std::multimap<long int, std::string> inverse_db;
};

#endif /* telephone_directory_hpp */
