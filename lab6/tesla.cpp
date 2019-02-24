#include <iostream>
#include <cstring>
#include <cctype>
#include <math.h>
#include <iomanip>

using namespace std;
bool check(int p){
  if(p>15 || p<0)
  cout<<"You cannot move that way! Try again."<<endl;
  return false;
}
int inputx(char a){
int x=0;
  if(a=='D'){
  x+=1;
  check(x);}
  else{
  x-=1;
check(x);}
return x;
  }
int inputy(char b){
  int y=0;
    if(b=='W'){
    y+=1;
    check(y);}
    else{
    y-=1;
  check(y);}
  return y;
    }
void input(char input){
  here:
  
  if(input=='W' || input=='S')
  inputy(input);
  else if (input=='A' || input=='D') {
  inputx(input);}
  else{
  cout<<"Invalid choice entered, try again."<<endl;
  goto here;}
  }


 
int main(){
 int x_elon=0,a;
 int y_elon=0;
 int x_yugo=6;
 int y_yugo=8;
 int x_pinto=11;
 int y_pinto=13;
 int xt=9;
 int yt=11;
 bool elon_awake=false;
  cout<<"Press W to move foreword, S to move backward, A to move left and D to move right."<<endl;
  cout<<"Pressing W/A/S/D and pressing return will move you one step in the specified direction."<<endl;
 
  if(rand()%5==3 || rand()%2==1)
  bool elon_awake=true;
  if(elon_awake==true){
    do{
    cout<<"You see a moving character in distant, be careful!!"<<endl; 
    x_elon+=rand()%15;
    y_elon+=rand()%15;

    if(input(a)==x_elon && input()==y_elon){
    c=c+1;
    if(c>=2)
    goto end;
    cout<<"Elon caught you roaming in unauthorized area!! You lied that you are the Janitor, and you are here to clean his bathroom."<<endl;
    cout<<"He lets you go, and you notice that he checks his phone for your employee records. He will probably know that you lied. Don't get caught again!"<<endl;}
    else if(abs(inputx()-x_elon)<=2 && abs(inputy()-y_elon)<=2)
    cout<<"Its Elon, you need to hide fast. Don't go near him."<<endl;
  }
    while(check(x)!=false && check(y)!=false);
    
    
  }
}
