#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
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

class Line
{
  friend ostream & operator<< (ostream & output, const Line & L)
  {
    output << "Point 1 is " << L.P1 << endl << "Point 2 is " << L.P2;
    return output;
  }

  friend istream & operator>> (istream & input, Line & L)
  {
    input >> L.P1 >> L.P2;
    return input;
  }

public:
  Line ()
  {
    P1.setX (0), P1.setY (0);
    P2.setX (0), P2.setY (0);
  }

  Line (Point p1, Point p2)
  {
    P1 = p1;
    P2 = p2;
  }
  Point getpoint1 ()
  {
    return P1;
  }
  Point getpoint2 ()
  {
    return P2;
  }
  double slope ()
  {
    double slope;
    if (P2.getX () == P1.getX ())
      {
	cout << "Slope is infinite, and placeholder value is: ";
	return NULL;
      }
    else
      {
	slope = (P2.getY () - P1.getY ()) / (P2.getY () - P1.getX ());
	return slope;
      }
  }
  double length ()
  {
    double length;
    length =
      sqrt (pow (P2.getX () - P1.getX (), 2) +
	    pow (P2.getY () - P1.getY (), 2));
    return length;
  }
  double yintercept ()
  {
    if (P2.getX () == P1.getX ())
      {
	cout << "No Y-intercept: and placeholder value is: ";
	return NULL;
      }
    else
      return (P1.getY () - (slope () * P1.getX ()));
  }
  string horizontal ()
  {
    if (P2.getY () == P1.getY ())
      return "Line 1 is horizontal.";
    else
      {
	return "Line 1 is not horizontal.";
      }
  }
  string vertical ()
  {
    if (P1.getX () == P2.getX ())
      return "Line 1 is vertical.";
    else
      return "Line 1 is not vertical.";
  }
  string parallel (Line L1, Line L2)
  {
    if (L2.slope () == L1.slope ())
      {
	return "Lines are parallel.";
      }
    else
      {
	return "Lines are not parallel.";
      }
  }
private:
  Point P1, P2;
};

int
main ()
{
  Line L1;
  Line L2;
  cout << "L1: should have all zeros for values" << endl;
  cout << L1 << endl;

  cout << "Enter Two Points For Line (x,y): ";
  cin >> L1;
  cout << "Enter Two Points for 2nd Line: ";
  cin >> L2;
  cout << "Slope of 1st line:" << L1.slope () << endl;
  L2.slope ();
  cout << "Length of 1st line:" << L1.length () << endl;
  cout << "Y-intercept of 1st line:" << L1.yintercept () << endl;
  cout << L1.horizontal () << endl;
  cout << L1.vertical () << endl;
  cout << L1.parallel (L1, L2) << endl;
  return 0;
}
