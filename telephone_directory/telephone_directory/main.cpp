#include <iostream>
#include <fstream>
#include "telephone_directory.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    string file = "/Users/christianmeyer/cpp/ch13/telephone_directory/data";
    fstream fs(file.c_str());
    int sz = 100;
    TelephoneDirectory TD;
    string name, telephone_string;
    string test_name; long long int test_num;
    for (int i = 0; i < sz; i++){
        getline(fs, name, '|');
        getline(fs, telephone_string);
        TD.add_entry(name, stol(telephone_string));
        if (i == 0){
            test_name = name;
            test_num = stol(telephone_string);
        }
    }
    TD.print_all();
    cout << endl;
    long int test_num_result = TD.find_entry(test_name);
    cout << test_name << " has number " << test_num_result << endl;
    vector<string> test_name_results = TD.find_entries(test_num);
    cout << "people with telephone number " << test_num << ":" << endl;
    for (int i = 0; i < test_name_results.size(); i++){
        cout << test_name_results[i] << endl;
    }
    
    cout << endl;
    return 0;
}
