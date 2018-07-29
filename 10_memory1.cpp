#include <iostream>

using std::cout;
using std::endl;

int* invalid_pointer() {
    int x = 42;
    return &x;
}
int* get_static_value() {
    static int x = 42;
    return &x; 	
}
int* get_new_int(){
    int* x = new int(21);
    return x;
}

int main() {
    cout << "Invalid: " << *invalid_pointer() << endl;
    cout << "Static : " << *get_static_value() << endl;

    int* p = get_new_int();
    cout << "Dynamic: " << *p << endl;
    delete p;
    cout << "Freed  : " << *p << endl;

    // Arrays work the same way:
    int* arr = new int[3];
    cout << "Array Addr: " << arr << endl;
    delete[] arr;
    cout << "Del Array : " << arr << endl;

    
}

