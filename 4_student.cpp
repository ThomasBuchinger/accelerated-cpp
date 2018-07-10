#include "4_student.h"

using std::istream;
using std::vector;

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
