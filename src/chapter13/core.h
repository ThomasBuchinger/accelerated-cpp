#ifndef GUARD_core_h
#define GUARD_core_h

#include <iostream>
#include <string>
#include <vector>
#include "../chapter4/grades.h"

class Core {
    friend class StudentInfo;
public:
    Core();
    Core(std::istream&);
    virtual ~Core() { }    

    std::string name() const { return n; };
    virtual std::istream& read(std::istream&);
    
    virtual double grade() const;

protected:
    double midterm_exam, final_exam;
    std::vector<double> homework;

    std::istream& read_common(std::istream&);
    std::istream& read_homework(std::istream&, std::vector<double>&);

    virtual Core* clone() const { return new Core(*this); }

private:
    std::string n;

};

bool compare(const Core&, const Core&);
bool compare_grades(const Core&, const Core&);

#endif
