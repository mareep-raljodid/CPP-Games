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

bool test(Point a, Point b, Point c){
    if((a.getx()*(b.gety()-c.gety())+b.getx()*(c.gety()-a.gety())+c.getx()*(a.gety()-b.gety()))==0)
        return true;
    else
        return false;
}
double distn(Point a, Point b){
    return sqrt((a.getx()-b.getx())*(a.getx()-b.getx())+(a.gety()-b.gety())*(a.gety()-b.gety()));
}

double perimeter(Point a, Point b, Point c){
    return (distn(a,b)+distn(b,c)+distn(c,a));
}

double area(double a, double b, double c, double p){
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main() {
    double a,b,c,p;
    double dist;
    Point p1;
    Point p2;
    Point p3;
    cout<<"Enter Point 1: ";
    cin>>p1;
    cout<<endl;
    
    cout<<"Enter Point 2: ";
    cin>>p2;
    cout<<endl;
    
    cout<<"Enter Point 3: ";
    cin>>p3;
    cout<<endl;
    /*cout<<"Enter another Point X: ";
     cin>>x2;
     cout<<endl;
     
     cout<<"Enter another Point Y: ";
     cin>>y2;
     cout<<endl;
     
     Point p1(x1,y1);
     Point p2(x2,y2);*/
    
    a=distn(p1,p2);
    b=distn(p2,p3);
    c=distn(p1,p3);
    p=perimeter(p1,p2,p3);
    
    
    
    
    if(test(p1,p2,p3))
        cout<<"Triangle is not possible."<<endl;
    else
    {
        
        cout<<"Triangle can be formed, Perimeter would be: "<<p<<endl<<"Area: "<<area(a,b,c,p/2)
        <<endl;
        if(fabs(a)==round(b) && round(b)==round(c) && round(a)==round(c))
           { cout<<"Triangle is equilateral."<<endl;cout<<endl;
            cout<<endl;}
        else{
            cout<<"Triangle is not equilateral"<<endl;
            cout<<endl;    }
    }

    cout<<"Point 1: "<<p1;
    cout<<endl;
    cout<<"Point 2: "<<p2;
    cout<<endl;
    cout<<"Point 2: "<<p3;
    cout<<endl;
}
