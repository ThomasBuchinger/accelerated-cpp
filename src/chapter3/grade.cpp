#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::streamsize;
using std::string;
using std::vector;

int main() {
    cout << "Please enter your name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << "Please enter your midterm and final exam grades: ";
    double midterm_grade, final_grade;
    cin >> midterm_grade >> final_grade;
   
    // Define some stuff
    vector<double> homework;
    double x;
    typedef vector<double>::size_type vec_sz;
    vec_sz homework_count;    

    // Read inputs
    // multiple strings without a operator between them, are concated implizitly.
    cout << "Enter " "your "  "homework " "grades "
         "followed by EOF: ";
    while(cin >> x) {
        homework.push_back(x);
    }

    // exit, if the user does not enter any homework grades
    homework_count = homework.size();
    if (homework_count == 0) { cout << "Please enter your homework grades..." << endl; return 1; }

    //compute median homework grade
    sort(homework.begin(), homework.end());
    vec_sz mid = homework_count/2;
    double median;
    median = homework_count % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2 : homework[mid];

    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << (0.2 * midterm_grade) + (0.4 * final_grade) + (0.4 * median)
         << setprecision(prec) << endl;

    return 0;
}
