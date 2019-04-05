#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
using namespace std;

class Point {
public:
    bool operator==(Point &rhs) {
        return (rhs.x == x && rhs.y == y);
    }
    
    bool operator!=(Point &rhs) {
        return (rhs.x != x || rhs.y != y);
    }
    
    friend ostream & operator<<( ostream &output, const Point &P ){
        output << "x: " << P.x << " y: " << P.y;
        return output;
    }
    
    friend istream & operator>>( istream &input, Point &P ){
        input >> P.x >> P.y;
        return input;
    }
    Point();
    Point(double, double);
    double gety(){
        return y;
    }
    double getx(){
        return x;
    }
private:
    double x,y;
};
Point::Point(){
    x=0.0;
    y=0.0;
    cout<<"Initially X and Y should be 0.0: ("<<x<<","<<y<<")"<<endl;
}
Point::Point(double ax, double ay){
    x=ax;
    y=ay;
    cout<<"X and Y value are: ("<<x<<","<<y<<")"<<endl;
}

bool test(Point a, Point b, Point c, Point d){
    int abb=0;
    if(a.getx()*(b.gety()-c.gety())+b.getx()*(c.gety()-a.gety())+ c.getx()*(a.gety()-b.gety())==0)
        abb=abb+1;
    if(b.getx()*(c.gety()-d.gety())+c.getx()*(d.gety()-b.gety())+ d.getx()*(b.gety()-c.gety())==0)
        abb=abb+1;
    if(a.getx()*(c.gety()-d.gety())+c.getx()*(d.gety()-a.gety())+ d.getx()*(c.gety()-a.gety())==0)
        abb=abb+1;
    if(a.getx()*(b.gety()-d.gety())+b.getx()*(d.gety()-a.gety())+ d.getx()*(a.gety()-b.gety())==0)
        abb=abb+1;
    
    if(abb>=1){
        return false;
    }
    else {
        return true;
    }


}
double distn(Point a, Point b){
    return sqrt((a.getx()-b.getx())*(a.getx()-b.getx())+(a.gety()-b.gety())*(a.gety()-b.gety()));
}


double area(Point a, Point b, Point c, Point d){
    return fabs(0.5 *  ( (a.getx()*b.gety()) + 
    (b.getx()*c.gety()) + (c.getx()*d.gety()) +
     (d.getx()*a.gety()) - (b.getx()*a.gety()) -
      (c.getx()*b.gety()) - (d.getx()*c.gety()) -
       (a.getx()*d.gety())));
}

int main() {
    double a,b,c,d,p;
    double dist;
    Point p1;
    Point p2;
    Point p3;
    Point p4;
    cout<<"Enter Point 1: ";
    cin>>p1;
    cout<<endl;
    
    cout<<"Enter Point 2: ";
    cin>>p2;
    cout<<endl;
    
    cout<<"Enter Point 3: ";
    cin>>p3;
    cout<<endl;

    cout<<"Enter Point 4: ";
    cin>>p4;
    cout<<endl;



    a=distn(p1,p2);
    b=distn(p2,p3);
    c=distn(p3,p4);
    d=distn(p4,p1);
    p=a+b+c+d;
    
    
    
    
    if(test(p1,p2,p3,p4)!=true)
        cout<<"Quadrilateral is not possible."<<endl;
    else
    {
        cout<<"Quadrilateral can be formed, Perimeter would be: "<<p
        <<endl<<"Area: "<<area(p1,p2,p3,p4)
        <<endl;
    }

    cout<<"Point 1: "<<p1;
    cout<<endl;
    cout<<"Point 2: "<<p2;
    cout<<endl;
    cout<<"Point 3: "<<p3;
    cout<<endl;
    cout<<"Point 4: "<<p4;
    cout<<endl;
}
