#include <algorithm>
#include <stdexcept>
#include <numeric>
#include <vector>
#include "../chapter4/student.h"
#include "../chapter4/grades.h"
#include "../chapter4/median.h"
#include "analysis_algorithm.h"

using std::vector;
using std::domain_error;

//median analysis
double grade_aux(const Student_info& s){
    try{
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm_exam, s.final_exam, 0);
    }
}
double median_analysis(const vector<Student_info>& students){
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
    return median(grades);
}

// average analysis
double average(const vector<double> v) {
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}
double average_grade(const Student_info& s) {
    return grade(s.midterm_exam, s.final_exam, average(s.homework));
}
double average_analysis(const vector<Student_info>& students){
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), average_grade);
    return median(grades);
}


// optimistic median
double optimistic_median(const Student_info& s) {
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
    
    if (nonzero.empty()) {
        return grade(s.midterm_exam, s.final_exam, 0);
    } else {
        return grade(s.midterm_exam, s.final_exam, median(nonzero));
    }
}
double optimistic_median_analysis(const vector<Student_info>& students){
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
    return median(grades);
}
