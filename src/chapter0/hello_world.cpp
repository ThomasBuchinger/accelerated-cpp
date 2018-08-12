// This is a Comment
#include <iostream>

void hello();
void hello_with_spaces();

int main () {
    hello();
    hello_with_spaces();
    return 0;
}

void hello_with_spaces() {
    std:: cout 
    <<
    "\tHello\tWorld \tWith\ttabs!" 
    <<
    std::endl;
    
}
void hello() {
    std::cout << "Hello world!" << std::endl;
}

