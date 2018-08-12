#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "../chapter6/more_algorithms.h"

using std::vector;
using std::map;
using std::string;
using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

#include <cstdio>
#include <string>
#include <cassert>

// RHEL C++ does not allow std:to_string function from C++ 11
// 
// see: https://stackoverflow.com/questions/4668760/converting-an-int-to-stdstring
std::string to_string(int);
std::string to_string( int x ) {
  int length = snprintf( NULL, 0, "%d", x );
  assert( length >= 0 );
  char* buf = new char[length + 1];
  snprintf( buf, length + 1, "%d", x );
  std::string str( buf );
  delete[] buf;
  return str;
}


map<string, vector<string> > xref(istream&, vector<string>(const string&));
map<string, vector<string> > xref(istream& in, vector<string> find_token(const string&) = split) {
    string line;
    int line_number = 0;
    map<string, vector<string> > ref;
    string loc;

    while (getline(in, line)) {
        line_number++;

        vector<string> tokens = find_token(line);
        for (vector<string>::const_iterator it = tokens.begin(); it !=tokens.end(); ++it) {
            loc = to_string(line_number);
            ref[*it].push_back(loc);
        }
    }
    return ref;
}

int main() {
    string filename = "text.txt";
    ifstream file(filename.c_str());
    map<string, vector<string> > ref = xref(file, find_urls);

    for (map<string, vector<string> >::const_iterator it = ref.begin(); it != ref.end(); ++it) {
        cout << it->first << " appeared on line(s): ";

        vector<string>::const_iterator lines = it->second.begin();
        cout << *(lines++);
        while (lines != it->second.end())
            cout << ", " << *(lines++);
        cout << endl;
    }

    return 0;
}
