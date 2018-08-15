#ifndef GUARD_grad_h
#define GUARD_grad_h

#include <iostream>
#include <string>
#include "core.h"

class Grad: public Core {
public:
    Grad(): thesis(0) { }
    Grad(std::istream&);

    std::istream& read(std::istream&);

    double grade() const;

private:
    double thesis;
    Grad* clone() const { return new Grad(*this); }

};

#endif
