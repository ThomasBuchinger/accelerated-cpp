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
 
// Helper function: is space or not space
bool space (char c) {
    return isspace(c);
}
bool not_space(char c) {
    return !isspace(c);
}

// split a string on whitepaces
vector<string> split(const string& str) {
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();
    while (i != str.end()) {
        i = find_if(i, str.end(), not_space);
        iter j = find_if(i, str.end(), space);

        if (i != str.end())
            ret.push_back(string(i, j));
        i = j;
    }
    return ret;
}

// check if a given string is a palindrom
bool is_palindrom(const string& str) {
    return equal(str.begin(), str.end(), str.rbegin());
}

vector<string> find_urls(const string& s) {
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin();
    iter e = s.end();

    while (b != e){
        // find the begin of the next url
        b = url_begin(b, e);

        // if we are not at the end, save the url to ret
        if (b != e) {
            iter end_of_url = url_end(b, e);
            ret.push_back(string(b, end_of_url));
            b = end_of_url;
        }
    }
    return ret;
}
bool not_url_char(char c) {
    static const string url_chars = "~;/?:@=&$-_.+!*'(),";
    return !( isalnum(c) || find(url_chars.begin(), url_chars.end(), c) != url_chars.end() );
}
string::const_iterator url_end(string::const_iterator b, string::const_iterator e) {
    return find_if(b,e, not_url_char);
}
string::const_iterator url_begin(string::const_iterator b, string::const_iterator e) {
    static const string sep = "://";
    typedef string::const_iterator iter;

    iter i = b;
    // while we are able to find new occureences of "://"
    //   sets i to the position of the nex occurence as a side-effect
    while ((i = search(i, e, sep.begin(), sep.end())) != e) {

        // check that the string starts or ends with "://"
        // if i is at the beginning, we would miss the protocol part of the url
        // if i is at the end, we would miss the server part of the url
        if ( i != b && i+sep.size() != e) {
            // find the protocol part
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;

            //check if there is a resource part after the "://"
            // beg != i : checks it the while actually did something
            if (beg != i && !(not_url_char(i[sep.size()])))
                return beg;
            
        }
        // we found a seperator, but it was not part of a valid url
        i += sep.size();
    }
    return e;
}




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
