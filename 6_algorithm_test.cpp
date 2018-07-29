#include <cctype>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "6_more_algorithms.h"


using std::vector;
using std::string;
using std::cout;
using std::endl;

// Main method
int main() {
    // string split function
    string split_test = "a b    c    def  ghijklm op q  srt uvw xyz";
    typedef vector<string>::const_iterator vec_iter;
    vector<string> splitted = split(split_test);
    for (vec_iter i = splitted.begin(); i != splitted.end(); ++i){
        cout << "split(): " << *i << endl;
    }

    // Check for palindroms
    vector<string> palindroms;
    palindroms.push_back( "iamnot a palindrom");
    palindroms.push_back("eye");
    palindroms.push_back( "doctor");
    palindroms.push_back( "regallager");
    string message;
    for (vec_iter i = palindroms.begin(); i != palindroms.end(); ++i){
        is_palindrom(*i) ? message = " yes" : message = " no";
        cout << "palindroms(): " << *i << message << endl;
    }

    // URL finder
    string text = ":// This a a url http://google.at but this is not ://, however ftp://kernel.org is cool anyway and stuff ://";
    vector<string> urls = find_urls(text);
    for (vec_iter i = urls.begin(); i != urls.end(); ++i){
        cout << "urls(): " << *i << endl;
    }



    return 0;
}
