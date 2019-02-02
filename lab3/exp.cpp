#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

// double factorial(int N) - returns the factorial variable N
// Please add the code necessary to calculate the factorial of the number represented by N

double factorial(int n) {
    int i;
    double f=1;
    if(n==0)
        return f;
    else
    {
        for(i=1;i<=n;i++)
            f=f*i;
        return f;}
}
// A clone of the system exp() function.
// Please do not use the system exp() function in the creation of your function.
double E_to_X(double x) {
    double e,xp;
    int i;
    for(i=1;i<=30;i++)
    {
        xp=xp+pow(x,i)/factorial(i);
    }
    e= 1+xp;
    return e;
    
}

// You can change main() in anyway you want
int main() {
    
    cout << fixed << "E_to_X(0) is " << E_to_X(0) << " should be 1" << endl;
    cout << fixed << "E_to_X(1) is " << E_to_X(1) << " should be 2.718" << endl;
    cout << fixed << "E_to_X(2) is " << E_to_X(2) << " should be 7.38" << endl;
    cout << fixed << "E_to_X(5) is " << E_to_X(5) << " should be 120" << endl;
    cout << fixed << "E_to_X(10) is " << E_to_X(10) << " should be 22026" << endl;
    
    return 0;
}
