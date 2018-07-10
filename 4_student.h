#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <iostream>
#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double midterm_exam;
    double final_exam;
    std::vector<double> homework;
}; // notice the semi-colon

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_homework(std::istream&, std::vector<double>&);

#endif
