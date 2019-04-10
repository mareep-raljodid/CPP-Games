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

bool
test (Point a, Point b, Point c, Point d)
{
  int abb = 0;
  if (a.getx () * (b.gety () - c.gety ()) +
      b.getx () * (c.gety () - a.gety ()) + c.getx () * (a.gety () -
							 b.gety ()) == 0)
    abb = abb + 1;
  if (b.getx () * (c.gety () - d.gety ()) +
      c.getx () * (d.gety () - b.gety ()) + d.getx () * (b.gety () -
							 c.gety ()) == 0)
    abb = abb + 1;
  if (a.getx () * (c.gety () - d.gety ()) +
      c.getx () * (d.gety () - a.gety ()) + d.getx () * (c.gety () -
							 a.gety ()) == 0)
    abb = abb + 1;
  if (a.getx () * (b.gety () - d.gety ()) +
      b.getx () * (d.gety () - a.gety ()) + d.getx () * (a.gety () -
							 b.gety ()) == 0)
    abb = abb + 1;

  if (abb >= 1)
    {
      return false;
    }
  else
    {
      return true;
    }


}


class Quadrilateral
{
  friend ostream & operator<< (ostream & output, Quadrilateral & Q)
  {
    output << "Point P1: " << Q.P1 << endl << "Point P2: " << Q.P2 << endl;
    output << "Point P3: " << Q.P3 << endl << "Point P4: " << Q.P4 << endl;
    output << (Q.
	       checkq ()? "Quadrilateral is Possible." :
	       "Quadrilateral is NOT Possible.");
    output << endl << "Area: " << Q.area () << endl;
    return output;
  }
  friend istream & operator>> (istream & input, Quadrilateral & Q)
  {
    input >> Q.P1 >> Q.P2 >> Q.P3 >> Q.P4;
    return input;
  }

public:
  Quadrilateral ()
  {
    PP1 (0, 0);
    PP2 (0, 0);
    PP3 (0, 0);
    PP4 (0, 0);
  }

  Quadrilateral (double x1, double y1, double x2, double y2,
		 double x3, double y3, double x4, double y4)
  {
    PP1 (x1, y1);
    PP2 (x2, y2);
    PP3 (x3, y3);
    PP4 (x4, y4);
  }

  void PP1 (double x, double y)
  {
    P1.dox (x);
    P1.doy (y);
  }

  void PP2 (double x, double y)
  {
    P2.dox (x);
    P2.doy (y);
  }

  void PP3 (double x, double y)
  {
    P3.dox (x);
    P3.doy (y);
  }

  void PP4 (double x, double y)
  {
    P4.dox (x);
    P4.doy (y);
  }

  Point getP1 ()
  {
    return P1;
  }

  Point getP2 ()
  {
    return P2;
  }

  Point getP3 ()
  {
    return P3;
  }

  Point getP4 ()
  {
    return P4;
  }

  bool checkq ()
  {
    double x1 = P1.getx ();
    double y1 = P1.gety ();
    double x2 = P2.getx ();
    double y2 = P2.gety ();
    double x3 = P3.getx ();
    double y3 = P3.gety ();
    double x4 = P4.getx ();
    double y4 = P4.gety ();
    return ((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) != 0) &&
      ((x2 * (y3 - y4) + x3 * (y4 - y2) + x4 * (y2 - y3)) != 0) &&
      ((x1 * (y3 - y4) + x3 * (y4 - y1) + x4 * (y3 - y1)) != 0) &&
      ((x1 * (y2 - y4) + x2 * (y4 - y1) + x4 * (y1 - y2)) != 0);
  }

  double area ()
  {
    double x1 = P1.getx ();
    double y1 = P1.gety ();
    double x2 = P2.getx ();
    double y2 = P2.gety ();
    double x3 = P3.getx ();
    double y3 = P3.gety ();
    double x4 = P4.getx ();
    double y4 = P4.gety ();
    return 0.5 * abs ((x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1)
		      - (y1 * x2 + y2 * x3 + y3 * x4 + y4 * x1));
  }

private:
  Point P1, P2, P3, P4;
};

int
main ()
{
  Quadrilateral Q1;
  Quadrilateral Q2;
  cout << "Enter points for Quadrilateral 1(eight space-seperated values): "
    << endl;
  cin >> Q1;
  cout << "Enter points for Quadrilateral 2(eight space-seperated values): "
    << endl;
  cin >> Q2;
  cout << "Required Information on Quadrilateral 1: " << endl << Q1 << endl;
  cout << "Required Information on Quadrilateral 2: " << endl << Q2 << endl;
  return 0;
}
