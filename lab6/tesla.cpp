#include <iostream>
#include <cstring>
#include <cctype>
#include <math.h>
#include <iomanip>

using namespace std;
int muskx=0, muskY=0;
bool
check (int p)
{
  if (p <= 15 || p >= 0)
    return true;
  else
    cout << "You cannot move that way! Try again." << endl;
}

int
elon_is_movingx ()
{
  muskx += rand () % 16 + 1;
  return muskx;
}

int
elon_is_movingy ()
{
  muskY += rand () % 16 + 1;
  return muskY;
}

int
check_if_caught (int a, int b, int xx, int yy)
{
  int c = 0;
  if (a == xx && b == yy)
    c = c + 1;
  return c;
}

int
main ()
{
  string dd = "";
  bool elon_awake;
  int a, ttt = 0;
  int b;
  int x_elon = 0;
  int y_elon = 0;
  int x_yugo = 6;
  int y_yugo = 8;
  int x_pinto = 11;
  int y_pinto = 13;
  int xt = 9;
  int yt = 11;
  int userx = 0;
  int usery = 0;
xxqw:
  cout <<
    "Press W to move foreword, S to move backward, A to move left and D to move right."
    << endl;
  cout <<
    "Pressing W/A/S/D and pressing return will move you one step in the specified direction."
    << endl;

  cout << "Enter your input (or E to exit): ";
  cin >> dd;
  here:
  if (dd.compare("W")==0)
    {
      userx += 1;
      if(check(userx)!=true)
      goto here;

    }
  else if (dd.compare("S")==0)
    {
      userx -= 1;
      if(check(userx)!=true)
      goto here;

    }
  else if (dd.compare("D")==0)
    {
      usery += 1;
      if(check(usery)!=true)
      goto here;

    }
  else if (dd.compare("A")==0)
    {
      usery -= 1;
      if(check(usery)!=true)
      goto here;

    }
  else if (dd.compare("E")==0)
	  goto end;
  else
  {
      cout<<"Wrong choice, please try again."<<endl;
      goto xxqw;}

  if (rand () % 5 == 3 || rand () % 2 == 1)
    bool elon_awake = true;
  if (elon_awake == true)
    {
      cout << "You see a moving character in distant, be careful!!" << endl;
      x_elon = elon_is_movingx ();
      y_elon = elon_is_movingy ();
      int ttt = check_if_caught (x_elon, y_elon, userx, usery);
      if (ttt != 0)
	{
	  //    c=0,a,b x_elon=0, y_elon=0,x_yugo=6, y_yugo=8,x_pinto=11,y_pinto=13,xt=9,yt=11;
	  cout <<
	    "Elon caught you roaming in unauthorized area!! You lied that you are the Janitor, and you are here to clean his bathroom."
	    << endl;
	  cout <<
	    "He lets you go, and you notice that he checks his phone for your employee records. He will probably know that you lied. Don't get caught again!"
	    << endl;
	}
      if (ttt >= 2)
	{
	  cout <<
	    "He caught you, you are the starman now. Good bye, have a great trip! You LOST!!"
	    << endl;
	  goto end;
	}
      if (userx == x_yugo && usery == y_yugo)
	cout <<
	  "You found a car!! You got in, but bad luck it was Yugo not a Tesla. He caught you, you are the starman now. Good bye, have a great trip! You LOST!!"
	  << endl;
      if (userx == x_pinto && usery == y_pinto)
	cout <<
	  "You found a car!! You got in, but bad luck it was Pinto not a Tesla. He caught you, you are the starman now. Good bye, have a great trip! You LOST!!"
	  << endl;
      if (userx == xt && usery == yt)
	{
	  cout << "You found a car!! You got in, and you realize..." << endl;
	  // delay(900);
	  cout << "IT WAS TESLA!!! YOU SAVED TESLA!! YOU WON!" << endl;
	}
    }
  else
    {
      //   c=0,a,b x_elon=0, y_elon=0,x_yugo=6, y_yugo=8,x_pinto=11,y_pinto=13,xt=9,yt=11;
      if (userx == x_yugo && usery == y_yugo)
	cout <<
	  "You found a car!! You got in, but bad luck it was Yugo not a Tesla. He caught you, you are the starman now. Good bye, have a great trip! You LOST!!"
	  << endl;
      if (userx == x_pinto && usery == y_pinto)
	cout <<
	  "You found a car!! You got in, but bad luck it was Pinto not a Tesla. He caught you, you are the starman now. Good bye, have a great trip! You LOST!!"
	  << endl;
      if (userx == xt && usery == yt)
	{
	  cout << "You found a car!! You got in, and you realize..." << endl;
	  //delay(900);
	  cout << "IT WAS TESLA!!! YOU SAVED TESLA!! YOU WON!" << endl;
	}

    }

  cout << "Enter another input (or E to exit): ";
  char h;
  cin >> h;
  if (dd.compare("E")==0)
    goto end;
  else
    goto here;
end:
  cout << "Game Over!! " << endl;
}
