#include <stdexcept>
#include <vector>
#include "grades.h"
#include "student.h"
#include "median.h"

using std::domain_error;
using std::vector;

// Compute the final grade
// from midterm, final and the overall homework
double grade(double midterm, double final_grade, double homework) {
    return 0.2 * midterm + 0.4 * final_grade, 0.4 * homework;
}

// Compute the final grade
// from midterm, final and ALL homeworks
double grade(double midterm, double final_grade, const vector<double>& homework) {
    if (homework.size() == 0)
        throw domain_error("student has not done any homework");
    return grade(midterm, final_grade, median(homework));
}

double grade(const Student_info& s) {
    return grade(s.midterm_exam, s.final_exam, s.homework);
}

