#include <iostream>
#include <string>

int main() {
    const int pad = 1;
    const int width_factor = 4;

    std::cout << "Please Enter your Name: ";    
    // Read the Name from STDIN
    std::string name;
    std::cin >> name;

    const std::string greeting = "Hello, " + name + "!";
    const int rows             = pad * 2 + 3;
    const int width            = 2 + pad * width_factor * 2 + greeting.size();

    std::cout << std::string(width, '*') << std::endl;
    int r = 1;
    while (r < rows-1) {
        if (r == rows/2) {
            //greeting line
            std::cout << "*" << std::string(pad*width_factor, ' ') << greeting << std::string(pad*width_factor, ' ') << "*" << std::endl;
        } else {
            std::cout << "*" << std::string(width-2, ' ') << "*" << std::endl;
        }
        r++;
    }
    std::cout << std::string(width, '*') << std::endl;
    return 0;
}
