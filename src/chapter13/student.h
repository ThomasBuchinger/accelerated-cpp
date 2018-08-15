#ifndef GUARD_student_h
#define GUARD_student_h

#include <iostream>
#include <string>
#include "core.h"

class StudentInfo {
public:
    StudentInfo(): cp(0) {}
    StudentInfo(std::istream& is): cp(0) { read(is); }
    StudentInfo(const StudentInfo&);
    StudentInfo& operator=(const StudentInfo&);
    ~StudentInfo() { delete cp; }

    std::istream& read(std::istream&);

    std::string name() const;
    double grade() const;
    static bool compare(const StudentInfo& s1, const StudentInfo& s2) {
        return s1.name() < s2.name();
    }

private:
    Core* cp;
};

#endif
