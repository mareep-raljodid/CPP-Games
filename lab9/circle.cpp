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

bool test(Point a, Point b){
    if(a==b)
        return true;
    else
        return false;
}

int main() {
    double x1,y1,x2,y2;
    double dist;
    
    Point p1;
    Point p2;
    cout<<"Enter Point 1: ";
    cin>>p1;
    cout<<endl;
    
    cout<<"Enter Point 2: ";
    cin>>p2;
    cout<<endl;
    
    /*cout<<"Enter another Point X: ";
     cin>>x2;
     cout<<endl;
     
     cout<<"Enter another Point Y: ";
     cin>>y2;
     cout<<endl;
     
     Point p1(x1,y1);
     Point p2(x2,y2);*/
    
    if(test(p1,p2))
        cout<<"Points are same, the circle cannot form because radius is 0"<<endl;
    else
    {
        dist=(sqrt(((p1.getx()-p2.getx())*(p1.getx()-p2.getx()))+((p1.gety()-p2.gety())*(p1.gety()-p2.gety()))));
        cout<<"Circle can be formed, radius would be: "<<dist<<endl<<"Diameter: "<<2*dist
        <<endl<<"Area: "<<2*dist*3.14<<endl;}
    
    return 0;
    
}
