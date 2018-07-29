#include <string>
#include <iostream>
#include <map>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::map;

int main() {
    string s;
    map<string, int> counters;
    
    while (cin >> s)
        counters[s]++;

    for (map<string, int>::const_iterator iter = counters.begin(); iter != counters.end(); ++iter)
        cout << iter->first << ": " << iter->second << endl;
    return 0;
}
