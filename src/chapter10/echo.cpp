#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char** argv) {
    if (argc > 1) {
        cout << argv[0] << " called with arguments: ";
        for(int i = 1; i < argc; ++i) {
            cout << argv[i] << "     ";
        }
        cout << endl;
    }
}
