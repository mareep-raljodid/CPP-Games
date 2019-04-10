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

class Triangle
{

  friend istream & operator>> (istream & input, Triangle & T)
  {
    input >> T.P1 >> T.P2 >> T.P3;
    return input;
  }

public:
    Triangle ()
  {
    PP1 (0, 0);
    PP2 (0, 0);
    PP3 (0, 0);
  }

  Triangle (double x1, double y1, double x2, double y2, double x3, double y3)
  {
    PP1 (x1, y1);
    PP2 (x2, y2);
    PP3 (x3, y3);
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

  bool check ()
  {
    return P1.getx () * (P2.gety () - P3.gety ())
      + P2.getx () * (P3.gety () - P1.gety ())
      + P3.getx () * (P1.gety () - P2.gety ()) == 0;
  }

  double area ()
  {
    double a = getSide1 ();
    double b = getSide2 ();
    double c = getSide3 ();
    double s = (a + b + c) / 2;
    return sqrt (s * (s - a) * (s - b) * (s - c));
  }

  double perimeter ()
  {
    return getSide1 () + getSide2 () + getSide3 ();
  }

  bool equilateral ()
  {
    return (abs (getSide1 () - getSide2 ()) < 0.001) &&
      (abs (getSide3 () - getSide2 ()) < 0.001);
  }

  bool operator== (Triangle & rhs)
  {
    if (!(rhs.check () && check ()))
      return false;
    bool P1s = ((rhs.getP1 () == P1)
		|| (rhs.getP1 () == P2) || (rhs.getP1 () == P3));
    bool P2s = ((rhs.getP2 () == P1)
		|| (rhs.getP2 () == P2) || (rhs.getP2 () == P3));
    bool P3s = ((rhs.getP3 () == P1)
		|| (rhs.getP3 () == P2) || (rhs.getP3 () == P3));
    return P1s && P2s && P3s;
  }

private:
  Point P1, P2, P3;
  double getSide1 ()
  {
    return sqrt (pow (P1.getx () - P2.getx (), 2) +
		 pow (P1.gety () - P2.gety (), 2));
  }
  double getSide2 ()
  {
    return sqrt (pow (P1.getx () - P3.getx (), 2) +
		 pow (P1.gety () - P3.gety (), 2));
  }
  double getSide3 ()
  {
    return sqrt (pow (P2.getx () - P3.getx (), 2) +
		 pow (P2.gety () - P3.gety (), 2));
  }
};


int
main ()
{
  Triangle T1;
  Triangle T2;
  cout << "Enter six space-seperated values for triangle 1:" << endl;
  cout << "Triangle 1: " << endl;
  cin >> T1;
  cout << "Enter six space-seperated values for triangle 2:" << endl;
  cout << "Triangle 1: " << endl;
  cin >> T2;

  cout << "Triangle 1: " << endl;
  cout << "Points YOU entered are: " << endl << T1.getP1 () << endl << T1.
    getP2 () << endl << T1.getP3 () << endl;
  if (T1.check ())
    {
      cout <<
	"Triangle is not possible!, re-run the program with different values."
	<< endl;
      return 0;
    }
  cout << "Perimeter of the triangle would be: " << T1.perimeter () << endl;
  cout << "Area: " << T1.area () << endl;
  if (T1.equilateral ())
    cout << "Triangle is Equilateral." << endl;

  cout << "Triangle 2: " << endl;
  cout << "Points YOU entered are: " << endl << T2.getP1 () << endl << T2.
    getP2 () << endl << T2.getP3 () << endl;
  if (T2.check ())
    {
      cout <<
	"Triangle is not possible!, re-run the program with different values."
	<< endl;
      return 0;
    }
  cout << "Perimeter of the triangle would be: " << T2.perimeter () << endl;
  cout << "Area: " << T2.area () << endl;
  if (T2.equilateral ())
    cout << "Triangle is Equilateral." << endl;

  if (T1 == T2)
    cout << "Triangles are Equal!";
}
