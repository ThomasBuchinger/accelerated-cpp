#ifndef GURAD_grades_h
#define GUARD_grades_h

#include <vector>
#include "median.h"
#include "student.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

#endif
