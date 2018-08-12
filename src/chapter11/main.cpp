#include <iostream>
#include <string>
#include "vec.h"

using std::cout;
using std::endl;
using std::string;

template <class T> void print_vec(const char* name, const T& v) {
    if (v.size() == 0){
       cout << name << ": is empty" << endl;
       return;
    }    
    typename T::const_iterator it = v.begin();
    cout << name << ": " << *it++;
    while(it != v.end()) {
        if (*it < 10) {
            cout << ",  " << *it++;
        } else {
            cout << ", " << *it++;
        }
    }
    cout << endl;
}

int main(){
    int max = 50;

    Vec<int> empty_v = Vec<int>();
    Vec<int> init_v  = Vec<int>(max, 5);
    Vec<int> copy_v  = Vec<int>(init_v);

    for(int i=0; i<max; ++i){
        empty_v.push_back(i);
    }

    print_vec("Range       ", empty_v);
    init_v[5] = 99;
    init_v[10] = 99;
    init_v[15] = 99;
    init_v[20] = 99;
    init_v[25] = 99;
    init_v[30] = 99;
    print_vec("Fives (orig)", init_v);
    print_vec("Fives (copy)", copy_v);

    copy_v.clear();
    print_vec("Copy (empty)", copy_v);
    // account for the alreadz deleted elements
    init_v.erase(5-0);
    init_v.erase(10-1);
    init_v.erase(15-2);
    init_v.erase(20-3);
    init_v.erase(25-4);
    init_v.erase(30-5);
    print_vec("Fives(short)", init_v);
    
    
    // This implementation is actually immun to deleting from an empty vector
    for(int i = 0; i < max+10; ++i){
        init_v.erase(1);
    }
    print_vec("small (last)", init_v);

}
