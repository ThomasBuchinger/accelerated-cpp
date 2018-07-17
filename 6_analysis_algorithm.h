#ifndef GUARD_6_analysis_algorithm_h
#define GUARD_6_analysis_algorithm_h

#include <algorithm>
#include <stdexcept>
#include <numeric>
#include <vector>
#include "4_student.h"
#include "4_grades.h"
#include "4_median.h"

double grade_aux(const Student_info&);
double median_analysis(const std::vector<Student_info>&);

double average(const std::vector<double>);
double average_grade(const Student_info&);
double average_analysis(const std::vector<Student_info>&);

double optimistic_median(const Student_info&);
double optimistic_median_analysis(const std::vector<Student_info>&);
#endif
