#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void get_point(double* p, int dim) {
    for(size_t i = 0; i < dim; ++i) {
        p[i] = 0.5 * ( i + 1);
    }
}

int main() {
    const size_t NDim  = 3;    // size_t is the max size for an array (depends in the implementation)
    double coord[NDim];       // Empty Array

    // The array variable, is a pointer to the first element
    // Therefore dereferencing will yield the first element in the array
    get_point(coord, NDim);
    cout << "Dereferencing a Array, returns the first element: " << *coord << endl;


    // Pointer work a lot like iterators
    // !!! This does look like bad coding practice? !!!
    cout << "I am at point: " << *coord;
    for(int i = 1; coord+i < coord+NDim; ++i ) {
        cout << ", " << coord[i];
    }
    cout << endl;

    // Array can be converted to vectors
    vector<double> v(coord, coord+NDim);

 
    // Strings are also just char-arrays
    const char hello_arr[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    string s1(hello_arr);     // Construct the string from a char-arraaay
    string s2("Hello");       // The compiler will expand the string literal into a char-array
    // construct the string from two iterators
    // NOTE: strlen returns the length without '\0'. the string constructor will reappend the lost '\0' char for us 
    string s3(hello_arr, hello_arr+strlen(hello_arr)); 
    cout << "s1 = " << s1 << ", s2 = " << s2 << ", s3 = " << s3 << endl;
    cout << "The Null Character: '" << *(hello_arr+strlen(hello_arr)) << "'" << endl;


    return 0;
}
