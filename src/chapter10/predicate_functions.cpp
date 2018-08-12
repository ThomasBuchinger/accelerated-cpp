#include <iostream>
#include <vector>
#include <math.h>

using std::cout;
using std::endl;
using std::vector;

// =================================================================
// = Main function
// ================================================================

template <class Iter, class Pred, class Container>
void find_all(Iter begin, Iter end, Container& vec, Pred predicate) {
    while (begin != end) {
        if (predicate(*begin)) {
            vec.push_back(*begin);
        }
        ++begin;
    }
    return;
}


// =================================================================
// = Predicate functions
// ================================================================

bool is_even(int n) {
    return n % 2 == 0;
}
bool is_prime(int n) {
    switch(n){
        case 0: return false;
        case 1: return false;
    }

    for(int i=2; i < n; ++i) {
        if( n % i == 0 )
            return false;
    }
    return true;
}
// A utility function that returns true if x is perfect square
bool is_perfect_square(int x)
{
    int s = sqrt(x);
    return (s*s == x);
}
 
// Returns true if n is a Fibinacci Number, else false
bool is_fibonacci(int n)
{
    // n is Fibinacci if one of 5*n*n + 4 or 5*n*n - 4 or both
    // is a perferct square
    return is_perfect_square(5*n*n + 4) ||
           is_perfect_square(5*n*n - 4);
}



// =================================================================
// =
// = Main & output 
// =
// ================================================================
template <class Iter>
void print(const char* name, Iter begin, Iter end) {
    cout << name << ": " << endl;
    while(begin != end) {
      cout << *begin << ", ";
      ++begin;
    }
    cout << endl << endl;
}

int main() {
    const int size = 1000;
    vector<int> numbers(size);
    for(int i=0; i < size; ++i) {
      numbers[i]=i;
    }

    vector<int> fib(0);
    find_all(numbers.begin(), numbers.end(), fib, is_fibonacci);
    print("Fibonacci Numbers", fib.begin(), fib.end());

    vector<int> perfect_square(0);
    find_all(numbers.begin(), numbers.end(), perfect_square, is_perfect_square);
    print("Perfect Squares", perfect_square.begin(), perfect_square.end());

    vector<int> primes(0);
    find_all(numbers.begin(), numbers.end(), primes, is_prime);
    print("Primes", primes.begin(), primes.end());
    
    return 0;
}
