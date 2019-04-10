#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include<string>
#include<fstream>
#include<cmath>

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

//triangle functions
bool
ttest (Point a, Point b, Point c)
{
  if ((a.getx () * (b.gety () - c.gety ()) +
       b.getx () * (c.gety () - a.gety ()) + c.getx () * (a.gety () -
							  b.gety ())) == 0)
    return true;
  else
    return false;
}

double
distn (Point a, Point b)
{
  return sqrt ((a.getx () - b.getx ()) * (a.getx () - b.getx ()) +
	       (a.gety () - b.gety ()) * (a.gety () - b.gety ()));
}

double
tperimeter (Point a, Point b, Point c)
{
  return (distn (a, b) + distn (b, c) + distn (c, a));
}

double
tarea (double a, double b, double c, double p)
{
  return sqrt (p * (p - a) * (p - b) * (p - c));
}

void
tmain (Point p1, Point p2, Point p3)
{
  double a, b, c, p;
  double dist;


  a = distn (p1, p2);
  b = distn (p2, p3);
  c = distn (p1, p3);
  p = tperimeter (p1, p2, p3);




  if (ttest (p1, p2, p3))
    cout << "Triangle is not possible." << endl;
  else
    {

      cout << "Triangle can be formed, Perimeter would be: " << p << endl <<
	"Area: " << tarea (a, b, c, p / 2) << endl;
      if (fabs (a) == round (b) && round (b) == round (c)
	  && round (a) == round (c))
	{
	  cout << "Triangle is equilateral." << endl;
	  cout << endl;
	  cout << endl;
	}
      else
	{
	  cout << "Triangle is not equilateral" << endl;
	  cout << endl;
	}
    }

  cout << "Point 1: " << p1;
  cout << endl;
  cout << "Point 2: " << p2;
  cout << endl;
  cout << "Point 2: " << p3;
  cout << endl;
}


bool
ctest (Point a, Point b)
{
  if (a == b)
    return true;
  else
    return false;
}

int
cmain (Point p1, Point p2)
{
  double x1, y1, x2, y2;
  double dist;



  if (ctest (p1, p2))
    cout << "Points are same, the circle cannot form because radius is 0" <<
      endl;
  else
    {
      dist =
	(sqrt
	 (((p1.getx () - p2.getx ()) * (p1.getx () - p2.getx ())) +
	  ((p1.gety () - p2.gety ()) * (p1.gety () - p2.gety ()))));
      cout << "Circle can be formed, radius would be: " << dist << endl <<
	"Diameter: " << 2 * dist << endl << "Area: " << 2 * dist *
	3.14 << endl;
    }

  return 0;

}


bool
qtest (Point a, Point b, Point c, Point d)
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



double
qarea (Point a, Point b, Point c, Point d)
{
  return fabs (0.5 * ((a.getx () * b.gety ()) +
		      (b.getx () * c.gety ()) + (c.getx () * d.gety ()) +
		      (d.getx () * a.gety ()) - (b.getx () * a.gety ()) -
		      (c.getx () * b.gety ()) - (d.getx () * c.gety ()) -
		      (a.getx () * d.gety ())));
}

void
qmain (Point p1, Point p2, Point p3, Point p4)
{
  double a, b, c, d, p;
  double dist;
  a = distn (p1, p2);
  b = distn (p2, p3);
  c = distn (p3, p4);
  d = distn (p4, p1);
  p = a + b + c + d;




  if (qtest (p1, p2, p3, p4) != true)
    cout << "Quadrilateral is not possible." << endl;
  else
    {
      cout << "Quadrilateral can be formed, Perimeter would be: " << p
	<< endl << "Area: " << qarea (p1, p2, p3, p4) << endl;
    }

  cout << "Point 1: " << p1;
  cout << endl;
  cout << "Point 2: " << p2;
  cout << endl;
  cout << "Point 3: " << p3;
  cout << endl;
  cout << "Point 4: " << p4;
  cout << endl;
}



int
numlines (string & fileName)
{
  int count = 0;
  string line;

  ifstream file (fileName);
  while (getline (file, line))
    count++;
  return count;
}


string
readFile (int input, string jj)
{
  ifstream file (jj);
  string in;
  vector < string > lines;
  if (file.is_open ())
    {

      while (getline (file, in))
	{
	  lines.push_back (in);
	}
      cout << in;

    }
  file.close ();
  return lines[input - 1];
}



vector < double >
breakupstring (string str)
{
  vector < double >numdata;
  stringstream ss;
  ss << str;

  while (!ss.eof ())
    {
      double temp;
      ss >> temp;
      numdata.push_back (temp);
    }

  return numdata;
}

int
main ()
{
  vector < double >numbh;
  string jj;
  string th;
  Point p1;
  Point p2;
  Point p3;
  Point p4;
  cout << "Input File Path with file name and extension: " << endl;
  cin >> jj;
  freopen ("shapes-info.txt", "w", stdout);
  int n = numlines (jj);
  for (int yy = 0; yy <= n; yy++)
    {
      string th = readFile (yy, jj);
      numbh = breakupstring (th);
      int sz = numbh.size ();
      if (sz == 4)
	{
	  Point p1 (numbh[0], numbh[1]);
	  Point p2 (numbh[2], numbh[3]);
	  cmain (p1, p2);
	  cout << endl;
	  cout << endl;
	}
      if (sz == 6)
	{
	  Point p1 (numbh[0], numbh[1]);
	  Point p2 (numbh[2], numbh[3]);
	  Point p3 (numbh[4], numbh[5]);
	  tmain (p1, p2, p3);
	  cout << endl;
	  cout << endl;
	}
      if (sz == 8)
	{
	  Point p1 (numbh[0], numbh[1]);
	  Point p2 (numbh[2], numbh[3]);
	  Point p3 (numbh[4], numbh[5]);
	  Point p4 (numbh[6], numbh[7]);
	  qmain (p1, p2, p3, p4);
	  cout << endl;
	  cout << endl;
	}
      else
	{
	  cout << endl;
	  cout << "Invalid number of coordinates provided" << endl;
	  cout << endl;
	}
    }
}
