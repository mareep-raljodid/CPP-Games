// Program: factorial.cpp
// Description: Test and develop the factorial function - main() has test
// code to check and see if the factorial() function works properly.

#include <iostream>
using namespace std;

// double factorial(int N) - returns the factorial variable N
// Please add the code necessary to calculate the factorial of the number represented by N

double factorial(int N) {
   // Please place the factorial of N in the variable return_val
   // so it can be returned to the calling function.
   double return_val = N;
// your code goes here
   return return_val;
}
// You can change main() in anyway you want
int main() {

	cout << fixed << "factorial(0) is " << factorial(0) << " should be 1" << endl;
	cout << fixed << "factorial(1) is " << factorial(1) << " should be 1" << endl;
	cout << fixed << "factorial(2) is " << factorial(2) << " should be 2" << endl;
	cout << fixed << "factorial(5) is " << factorial(5) << " should be 120" << endl;
	cout << fixed << "factorial(10) is " << factorial(10) << " should be 3628800" << endl;
	// this may not work
	cout << fixed << "factorial(20) is " << factorial(20) << " should be 1307674368000" << endl;





	return 0;
}
