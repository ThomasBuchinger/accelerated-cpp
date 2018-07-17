#include "4_student.h"
#include <algorithm>
#include <fstream>

using std::istream;
using std::vector;
using std::string;
using std::ifstream;

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s) {
    is >> s.name >> s.midterm_exam >> s.final_exam;
    read_homework(is, s.homework);
    return is;
}


istream& read_homework(istream& in, vector<double>& homework) {
    if (in) {
        homework.clear();

        double x;
        while(in >> x) {
            homework.push_back(x);
        }
        
        in.clear();
    }
    return in;
}

// Added in Chapter 6
bool did_all_hw(const Student_info& s) {
    return find(s.homework.begin(), s.homework.end(), 0) == s.homework.end();
}
void open_class(string filename, vector<Student_info>& students) {
    ifstream class_file; 
    class_file.open(filename.c_str());
    Student_info record;
    while (read(class_file, record)) {
        students.push_back(record);
    }    
    class_file.close();
}

