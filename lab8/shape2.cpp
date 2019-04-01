#include <iostream>

using namespace std;

class cuboid
{
    double h;
    double l;
    double w;
public:
    void val ()
    {
        cout << "\nEnter length of a side: ";
        cin >> l;
        cout << "\nEnter breadth: " << endl;
        cin >> h;
        cout << "Enter Width: " << endl;
        cin >> w;
    }
    double sa ()
    {
        double sua;
        sua = ((l * w) + (l * h) + (h * w)) * 2;
        return sua;
    }
    double v ()
    {
        double vol;
        vol = l * w * h;
        return vol;
    }
};

int
main ()
{
    cuboid s;
    s.val ();
    cout << "\nTHE SURFACE AREA IS:" << s.sa ();
    cout << "\nTHE VOLUME IS:" << s.v () << endl;
}
