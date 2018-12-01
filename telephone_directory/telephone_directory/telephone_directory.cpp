#include "telephone_directory.hpp"

void TelephoneDirectory::add_entry(std::string n, long int tele){
    db[n] = tele;
    inverse_db.insert(make_pair(tele, n));
}
long int TelephoneDirectory::find_entry(std::string n){
    std::map<std::string, long int>::iterator pos = db.find(n);
    if (pos == db.end()) return 0;
    else return pos->second;
}
std::vector<std::string> TelephoneDirectory::find_entries(long int tele){
    std::multimap<long int, std::string>::iterator lower = inverse_db.lower_bound(tele);
    std::multimap<long int, std::string>::iterator upper = inverse_db.upper_bound(tele);
    std::vector<std::string> results;
    for (std::multimap<long int, std::string>::iterator pos = lower; pos != upper; pos++){
        results.push_back(pos->second);
    }
    return results;
}
void TelephoneDirectory::print_all(){
    std::map<std::string, long int>::iterator first = db.begin();
    std::map<std::string, long int>::iterator stop = db.end();
    for (std::map<std::string, long int>::iterator pos = first; pos != stop; pos++){
        std::cout << pos->first << " : " << pos->second << std::endl;
    }
}
