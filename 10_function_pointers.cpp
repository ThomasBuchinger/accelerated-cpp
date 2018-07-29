#include <iostream>

using std::cout;
using std::endl;
typedef int (*function_pointer)(int);

int next(int n) { 
    return n + 1;
}

function_pointer get_next_fp() {
    return &next;
}

int main() {
    int x = 42;

    // just a normal function call 
    int a = next(x);
    cout << "normal call: a = " << a << endl;

    // these two are equivalent
    function_pointer fp = next;
    function_pointer fp2 = &next;

    // A function pointer can be called, just like the function
    int b = (*fp)(x);
    int c = fp2(x);
    cout << "implicit call: b = " << b << ", c = " << c << endl;

    // A function pointer can also be returned from a function
    function_pointer fp3 = get_next_fp();
    // arcane, but does not need the typedef
    int(*fp4)(int) = get_next_fp();

    int d = fp3(x);
    int e = fp4(x);
    cout << "FP returned from function: d = " << d << ", e = " << e << endl;
}
