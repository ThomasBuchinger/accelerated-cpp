#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

string letter_grade(double grade) {
    static const double grade_limits[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
    };
    static const char* const letters[] = {
        "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };
    static const size_t ngrades = sizeof(grade_limits)/sizeof(*grade_limits);


    for (size_t i = 0; i < ngrades; ++i) {
        if( grade >= grade_limits[i] ) {
            return letters[i];
        }
    }
    return "?\?\?";
}

int main() {
    double grade = 97.6;
    cout << "Your Grade: " << letter_grade(grade) << endl;
    return 0;
}
