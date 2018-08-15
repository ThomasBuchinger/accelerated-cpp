#include <iostream>
#include <string>
#include <vector>
#include "core.h"
#include "../chapter4/grades.h"

using std::string;
using std::vector;
using std::istream;

Core::Core(): midterm_exam(0), final_exam(0) { }
Core::Core(istream& in) {
    read(in);
}

istream& Core::read(istream& in){
    read_common(in);
    read_homework(in, homework);
    return in;
}

double Core::grade() const {
    return ::grade(midterm_exam, final_exam, homework);
}

istream& Core::read_common(std::istream& in) {
    in >> n >> midterm_exam >> final_exam;
    return in;
}
istream& Core::read_homework(istream& in, vector<double>& homework) {
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


bool compare(const Core& c1, const Core& c2) {
    return c1.name() < c2.name();
}
bool compare_grades(const Core& c1, const Core& c2) {
    return c1.grade() < c2.grade();
}


