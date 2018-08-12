#include <iostream>
#include <string>

int main() {
    std::cout << "Please Enter your Name: ";    
    // Read the Name from STDIN
    std::string name;
    std::cin >> name;

    const std::string greeting = " Hello, " + name + "! ";
    // Note: top and bottom are equivalent
    const std::string top      = std::string(greeting.size(), '-');
    const std::string bottom(greeting.size(), '_');
    
    std::cout << "|" << top      << '|'  << std::endl;
    std::cout << "|" << greeting << "|" << std::endl;
    std::cout << "|" << bottom   << "|" << std::endl;
    return 0;
}
