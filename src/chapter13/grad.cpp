#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "grad.h"

using std::string;
using std::vector;
using std::istream;

Grad::Grad(istream& in) {
    read(in);
}

istream& Grad::read(istream& in){
    read_common(in);
    in >> thesis;
    read_homework(in, homework);
    return in;
}

double Grad::grade() const {
    return std::min(thesis, Core::grade());
}


