#include <iostream>

using namespace std;


class cube
{
    
    double h;
    
    double l;
    
    double w;
    
public:
    void val ()
    {
        
        cout << "\nEnter length of a side: ";
        
        cin >> l;
        
    }
    double sa ()
    {
        
        double sua;
        
        sua = 6 * (l * l);
        
        return sua;
        
    }
    
    double v ()
    {
        
        double vol;
        
        vol = l * l * l;
        
        return vol;
        
    }
    
};



int
main ()
{
    
    cube s;
    
    s.val ();
    
    cout << "\nTHE SURFACE AREA IS:" << s.sa ();
    
    cout << "\nTHE VOLUME IS:" << s.v () << endl;
    
}
