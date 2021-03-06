#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grades.h"
#include "student.h"

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::streamsize;
using std::domain_error;
using std::sort;
using std::max;
using std::string;
using std::vector;

int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while(read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0;
            i != students.size(); ++i) {
        // write the output
        cout << students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ');
        try {
            double overall_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3)
                 << overall_grade
                 << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what();
            return 1;
        }
    }
    return 0;
}
