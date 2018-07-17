#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "4_student.h"
#include "4_grades.h"
#include "4_median.h"
#include "6_analysis_algorithm.h"

using std::istream;
using std::ostream;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void write_analysis(ostream&, const string&, double (const vector<Student_info>&), const vector<Student_info>&, const vector<Student_info>&);
void write_analysis(ostream& out, 
                    const string& name, 
                    double analysis(const vector<Student_info>&), 
                    const vector<Student_info>& did, 
                    const vector<Student_info>& didnt){
    out << name << ": did=" << analysis(did) << " - didnt=" << analysis(didnt) << endl;
}

int main() {
    vector<Student_info> students;
    open_class("class.txt", students);
    typedef vector<Student_info>::const_iterator iter;


    /* There is a better way to seperate the students!
     *  
    vector<Student_info> did;
    vector<Student_info> didnt;    
    for (iter i = students.begin(); i != students.end(); ++i) {
        if (did_all_hw(*i)) {
            did.push_back(*i);
        } else {
            didnt.push_back(*i);
        }
    }
    */
    // sort the students vector, that all students with all the homework are on the beginning and the others at the end
    //   lazy_students is a iterator, merking the first element of the second partition
    vector<Student_info>::iterator lazy_students = stable_partition(students.begin(), students.end(), did_all_hw);
    // Copy the lazy_students in their own vector
    vector<Student_info> didnt(lazy_students, students.end());
    // Remove lazy_students from the original vector
    students.erase(lazy_students, students.end());
    vector<Student_info> did = students;


    if (did.empty()) {
        cout << "No Student did all the homework!" << endl;
        return 1;
    }
    if (didnt.empty()) {
       cout << "All students did all the homework" << endl;
       return 2;
    }

    write_analysis(cout, "median", median_analysis, did, didnt); 
    write_analysis(cout, "average", average_analysis, did, didnt); 
    write_analysis(cout, "optimistic", optimistic_median_analysis, did, didnt); 


    return 0;
}
