#ifndef GUARD_Str_h
#define GUARD_Str_h

#include <cstring>
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>

#include "../chapter11/vec.h"

class Str {
public:

    // typedef
    friend std::istream& operator>>(std::istream&, Str&);
    typedef Vec<char>::size_type size_type;

    // constructor
    Str(){ }
    Str(size_type n, char c): data(n,c) { }
    Str(const char* cp) {
        std::copy(cp, cp+std::strlen(cp), std::back_inserter(data));
    }
    template <class Iter> Str(Iter b, Iter e) {
        std::copy(b,e, std::back_inserter(data));
    }
    Str(const std::string& s) {  
        std::copy(s.begin(), s.end(), std::back_inserter(data));
    }

    // destructor not needed, since the default will forward all the work to Vec
    
    // operations
    char& operator[] (size_type i)             { return data[i]; }
    const char& operator[] (size_type i) const { return data[i]; }
    Str& operator+=(const Str& s) {
        std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
        return *this;
    }

    // member functions
    size_type size() const { return data.size(); }

private:
     Vec<char> data;

};
Str operator+(const Str& s1, const Str& s2);

// not needed, since it is defined as friend
// std::istream& operator>>(std::istream&, Str&);
std::ostream& operator<<(std::ostream&, const Str&);


Str operator+(const Str& s1, const Str& s2) {
    Str ret = s1;
    ret += s2;
    return ret;
}


std::ostream& operator<<(std::ostream& os, const Str& s){
    Str::size_type len = s.size();
    for(Str::size_type i = 0; i != len; ++i) {
        os << s[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, Str& s) {
    s.data.clear();
    
    char c;
    while (is.get(c) && isspace(c)) { }

    if(is) {
        do {
            s.data.push_back(c);
        } while(is.get(c) && !isspace(c));

        if(is) { is.unget(); }
    }
    return is;
}


#endif
