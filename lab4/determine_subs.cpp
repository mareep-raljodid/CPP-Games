#include <iostream>

using namespace std;

// Please place your "determine substance" function and body
// See google docs for details

int main() {  //NO NEED TO CHANGE THIS
    double bp = 100;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Water" << endl;
    bp = 350;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Mecury" << endl;
    bp = 2100;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Silver" << endl;
    bp = 1100;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Unknown" << endl;
    bp = 1150;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Copper" << endl;
    bp = 2600;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Gold" << endl;
    bp = 11000;
    cout << "Substance function returns: " << determineSubstance(bp)
         << " for a temperature of " << bp << " Should be Known" << endl;
    return 0;
}
