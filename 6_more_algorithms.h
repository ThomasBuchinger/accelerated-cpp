#ifndef GUARD_6algorithms
#define GUARD_6algorithms

#include <cctype>
#include <algorithm>

bool space (char c);
bool not_space(char c);
std::vector<std::string> split(const std::string& str);
bool is_palindrom(const std::string& str);

std::vector<std::string> find_urls(const std::string& s);
std::string::const_iterator url_end(std::string::const_iterator b, std::string::const_iterator e);
bool not_url_char(char c);
std::string::const_iterator url_begin(std::string::const_iterator b, std::string::const_iterator e);


#endif
