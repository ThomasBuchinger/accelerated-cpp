#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "core.h"
#include "grad.h"


using std::cout;
using std::cin;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

int main() {
    string filename("university_class.txt");

    vector<Core> students;
    Core record;
    string::size_type maxlen = 0;

    ifstream class_file; 
    class_file.open(filename.c_str());
    while (record.read(class_file)) {
        maxlen = std::max(maxlen, record.name().size());
        students.push_back(record);
    }    
    class_file.close();

    sort(students.begin(), students.end(), compare_grades);

    for(vector<Core>::size_type i = 0; i != students.size(); ++i) {
        Core s = students[i];
        cout << s.name() << string((maxlen+1 - s.name().size()),' ') 
             <<": " << s.grade() << endl;
    }
    return 0;
}
