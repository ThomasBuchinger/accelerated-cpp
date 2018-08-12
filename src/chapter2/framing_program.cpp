#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
    const int pad = 1;
    const int width_factor = 8;

    // Get user input
    cout << "Please enter your name: ";
    string name;
    cin  >> name;
    cout << endl;

    // define some variables
    const string greeting        = "Hello, " + name + "!";
    const int rows               = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * width_factor * 2 + 2;

    for(int r = 0; r != rows; r++) {
        for(string::size_type c = 0; c != cols; c++ ){

            // Are we at the start of the greeting?
            if (r == pad + 1 && c == pad * width_factor + 1) {
                cout << greeting;
                c += greeting.size() - 1; // The for loop expects us to write on char at a time
            } else {
                if (r == 0 || r == rows-1 || c == 0 || c == cols-1) {
                    cout << '*';
                } else {
                    cout << ' ';
                }
            }
        }
        cout << endl;
    }
    return 0;
}
