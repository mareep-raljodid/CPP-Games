#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
using namespace std;

class Point
{
public:
  bool operator== (Point & rhs)
  {
    return (rhs.x == x && rhs.y == y);
  }

  bool operator!= (Point & rhs)
  {
    return (rhs.x != x || rhs.y != y);
  }

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
  Point ();
  Point (double, double);
  double gety ()
  {
    return y;
  }
  double getx ()
  {
    return x;
  }
  void dox (double this_x)
  {
    x = this_x;
  }
  void doy (double this_y)
  {
    y = this_y;
  }

private:
  double x, y;
};

Point::Point ()
{
  x = 0.0;
  y = 0.0;
  cout << "Initially X and Y should be 0.0: (" << x << "," << y << ")" <<
    endl;
}

Point::Point (double ax, double ay)
{
  x = ax;
  y = ay;
  cout << "X and Y value are: (" << x << "," << y << ")" << endl;
}

class Circle
{

  friend istream & operator>> (istream & input, Circle & C)
  {
    input >> C.P1 >> C.P2;
    return input;
  }

public:
    Circle ()
  {
    setP1 (0, 0);
    setP2 (0, 0);
  }

  Circle (double x1, double y1, double x2, double y2)
  {
    setP1 (x1, y1);
    setP2 (x2, y2);
  }

  void setP1 (double x, double y)
  {
    P1.dox (x);
    P1.doy (y);
  }

  void setP2 (double x, double y)
  {
    P2.dox (x);
    P2.doy (y);
  }

  Point getP1 ()
  {
    return P1;
  }

  Point getP2 ()
  {
    return P2;
  }

  bool check ()
  {
    return (P1 == P2);
  }

  double radius ()
  {
    return sqrt (pow (P1.getx () - P2.getx (), 2) +
		 pow (P1.gety () - P2.gety (), 2));
  }

  double diameter ()
  {
    return 2 * radius ();
  }

  double circump ()
  {
    return diameter () * 3.14;
  }

  double area ()
  {
    return radius () * radius () * 3.14;
  }

  bool operator== (Circle & rhs)
  {
    if (!(rhs.check () && check ()))
      return false;
    return (rhs.getP1 () == P1 && rhs.radius () == radius ());
  }

private:
  Point P1, P2;
};

int
main ()
{
  Circle C1;
  cout << "Enter four space-seperated values for circle 1:" << endl;
  cout << "Circle 1: " << endl;
  cin >> C1;
  Circle C2;
  cout << "Enter four space-seperated values for circle 2:" << endl;
  cout << "Circle 2: " << endl;
  cin >> C2;

  if (C1.check ())
    cout << "Circle 1 cannot form." << endl;

  if (C2.check ())
    cout << "Circle 2 cannot form." << endl;

  cout << "Center Point of the circle 1 : " << C1.getP1 () << endl;
  cout << "Point on the circumference of the circle 1 : " << C1.
    getP2 () << endl;
  cout << "Radius: " << C1.radius () << endl << "Diameter: " << C1.
    diameter () << endl << "Circumference: " << C1.
    circump () << endl << "Area: " << C1.area () << endl;

  cout << "Center Point of the circle 2 : " << C1.getP1 () << endl;
  cout << "Point on the circumference of the circle 2 : " << C1.
    getP2 () << endl;
  cout << "Radius: " << C1.radius () << endl << "Diameter: " << C1.
    diameter () << endl << "Circumference: " << C1.
    circump () << endl << "Area: " << C1.area () << endl;


  if (C1 == C2)
    {
      cout << "Both circles are same." << endl;
    }
}
