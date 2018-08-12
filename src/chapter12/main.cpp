#include <iostream>
#include <string>
#include "str.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


int main(){

   Str s1 = Str("Hello world!");
   cout << s1 << endl;

   Str s2 = Str("I am ");
   Str s3 = Str("a ");
   cout << (s2 + s3 + "compound " + string("string")) << endl;

   Str input;
   cout << "Enter your name: ";
   cin >> input;
   cout << endl << "Hello " << input << endl;

}
