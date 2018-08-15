#include <iostream>
#include <stdexcept>
#include <string>
#include "student.h"
#include "core.h"
#include "grad.h"

using std::string;
using std::istream;

string StudentInfo::name() const {
    if (cp) cp->name();
    else throw std::runtime_error("Uninitialized Student");
}
double StudentInfo::grade() const {
    if (cp) cp->grade();
    else throw std::runtime_error("Uninitialized Student");
}
istream& StudentInfo::read(istream& in) {
    delete cp;

    char ch;
    in >> ch;
    if (ch == 'G') cp = new Grad(in);
    else cp = new Core(in);

    return in;
}
StudentInfo::StudentInfo(const StudentInfo& s): cp(0) {
    if (s.cp) cp = s.cp->clone();
}
StudentInfo& StudentInfo::operator=(const StudentInfo& s) {
    if (&s != this) {
        delete cp;

        if (s.cp) cp = s.cp->clone();
        else cp = 0;
    }
    return *this;
}

