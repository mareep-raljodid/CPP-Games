#include <iostream>
#include <string>
#include <vector>
#include <cctype>

 using namespace std;

class Point
{
  
friend ostream & operator<< (ostream & output, const Point & P)
  {
    
output << "x: " << P.x << " y: " << P.y;
    
return output;
  
}
  
 
friend istream & operator>> (istream & input, Point & P)
  {
    
input >> P.x >> P.y;
    
return input;
  
}

 
public:
Point ()
  {
    
x = 0;
    
y = 0;
  
}
  
Point (int in_x, int in_y)
  {
    
setX (in_x);
    
setY (in_y);
  
} 
 
int getX ()
  {
    
return x;
  
}
  
 
int getY ()
  {
    
return y;
  
}
  
 
void setX (int in_x)
  {
    
x = in_x;
  
} 
 
void setY (int in_y)
  {
    
y = in_y;

} 
 
private:
int x, y;

};


 
int
main ()
{
  
Point P1;
  
Point P2 (13, 5);
  
cout << "Point P1 should have 0,0 as values" << endl;
  
cout << P1 << endl;
  
cout << "Point P2 should have 13,5 as values" << endl;
  
cout << P2 << endl;
  
 
cout << "Enter x and y points: for instance 3<space>4 ";
  
cin >> P1;
  
cout << P1 << endl;
  
 
return 0;

}


