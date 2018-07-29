#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <map>
#include <ctime>
#include "6_more_algorithms.h"

using std::string;
using std::cout;
using std::endl;
using std::istream;
using std::ifstream;
using std::vector;
using std::map;
using std::domain_error;
using std::logic_error;
using std::time;

typedef vector<string> Rule;
typedef vector<Rule> RuleCollection;
typedef map<string, RuleCollection> Grammar;


Grammar read_grammar(istream&);
Grammar read_grammar(istream& in) {
    Grammar ret;
    string line;
    
    while (getline(in, line)) {
        vector<string> entry = split(line);
        if (!entry.empty()) {
            ret[entry[0]].push_back(Rule(entry.begin()+1, entry.end()));
        }
    }
    return ret;
}

int nrand(int);
int nrand(int n) {

    if ( n <= 0 || n > RAND_MAX )
        domain_error("Argument to nrand it out of range");

    const int bucket_size = RAND_MAX / n;
    int r;
    do {
     r = rand() / bucket_size;
    } while (r >= n);

    return r;
}
bool is_token(const string&);
bool is_token(const string& s) {
    return s.size() > 1 && s[0] == '<' && s[s.size()-1] == '>';
}

void gen_aux(const Grammar&, const string&, vector<string>&);
void gen_aux(const Grammar& g, const string& token, vector<string>& sentence){
    if (!is_token(token)) {
        sentence.push_back(token);
    } else {
        Grammar::const_iterator it = g.find(token);
        
        if (it == g.end())
            throw logic_error("empty rule");

        const RuleCollection c = it->second;
        const Rule& r = c[nrand(c.size())];

        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i) {
            gen_aux(g, *i, sentence);
        }

    }
}

int main() {
    string grammar_file = "grammar.txt";
    ifstream file(grammar_file.c_str());
    Grammar grammar = read_grammar(file);

    srand(time(NULL));

    for (int i = 0; i <= 10; ++i) {
    vector<string> sentence;
    gen_aux(grammar, "<sentence>", sentence);


    vector<string>::const_iterator it = sentence.begin();
    if (!sentence.empty())
       cout << *it++;

    while (it != sentence.end())
       cout << " " << *it++;

    cout << endl;
    }
    return 0;
}
