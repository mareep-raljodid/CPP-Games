
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
  
using namespace std;

 
class stringManip
{

public:
stringManip ();
  
stringManip (string input);
  
string retrieve ();
  
void setString (string input);
  
void chop ();
  
void padString (int n);
  
void center (int length);
  
void truncate (int n);
  
void removeNonAlpha ();
  
void convertToUpperCase ();
  
void convertToLowerCase ();
  
void size ()
  {
    
cout << tobeEdited.size ();

} 
private:
string tobeEdited;

};


 
stringManip::stringManip ()
{
  
tobeEdited = "";

} 
 
stringManip::stringManip (string in_string)
{
  
tobeEdited = in_string;

} 
 
string stringManip::retrieve ()
{
  
return tobeEdited;

}


 
void
stringManip::padString (int l)
{
  
int size = tobeEdited.size ();
  
if (l > size)
    {
      
tobeEdited.resize (l);
      
for (int i = size; i < l; ++i)
	{
	  
tobeEdited.at (i) = ' ';
    
} 
}

} 
 
void

stringManip::setString (string x)
{
  
tobeEdited = x;

} 
 
void

stringManip::chop ()
{
  
if (tobeEdited != "")
    {
      
string str = "";
      
int rr;
      
int tt;
      
for (int i = 0; i < tobeEdited.size (); ++i)
	{
	  
if (isspace (tobeEdited.at (i)) == false)
	    {
	      
rr = i;
	      
break;
	    
}
	
 
}
      
 
for (int i = tobeEdited.size () - 1; i >= 0; --i)
	{
	  
if (isspace (tobeEdited.at (i)) == false)
	    {
	      
tt = i;
	      
 
break;
	    
}
	
}
      
 
for (int i = rr; i < tt + 1; ++i)
	{
	  
 
str += tobeEdited.at (i);
	
} 
tobeEdited = str;
    
}

} 
 

//center the string when given a length
  void
stringManip::center (int l)
{
  
chop ();
  
string str = tobeEdited;
  
int extra = fabs (l - str.size ());
  
cout << str.size () << endl;
  
if (extra % 2 == 0)
    {
      
int i = 0;
      
while (i < extra / 2)
	{
	  
str.insert (i, " ");
	  
++i;
	
}
      
str.resize (l);
      
i = str.size () - 1;
      
int itr = 0;
      
while (itr < extra / 2)
	{
	  
str.at (i) = ' ';
	  
--i;
	  
++itr;
	
}
    
}
  
  else if (extra % 2 != 0)
    {
      
int i = 0;
      
while (i < extra / 2)
	{
	  
str.insert (i, " ");
	  
++i;
	
}
      
str.resize (l);
      
i = str.size () - 1;
      
int itr = 0;
      
while (itr < ((extra / 2) + 1))
	{
	  
str.at (i) = ' ';
	  
--i;
	  
++itr;
	
}
    
}
  
tobeEdited = str;

}


 
void
stringManip::truncate (int n)
{
  
string str = "";
  
if (tobeEdited.size () > n)
    {
      
for (int i = 0; i < n; ++i)
	{
	  
str = str + tobeEdited.at (i);
	
} 
tobeEdited = str;
    
}

 
 
} 
 
void

stringManip::removeNonAlpha ()
{
  
string str = "";
  
for (int i = 0; i < tobeEdited.size (); ++i)
    {
      
if (isalpha (tobeEdited.at (i)))
	{
	  
str = str + tobeEdited.at (i);
	
}
    
}
  
tobeEdited = str;

}


 
void
stringManip::convertToUpperCase ()
{
  
for (int i = 0; i < tobeEdited.size (); ++i)
    {
      
tobeEdited.at (i) = toupper (tobeEdited.at (i));

} 
} 
 
void

stringManip::convertToLowerCase ()
{
  
for (int i = 0; i < tobeEdited.size (); ++i)
    {
      
tobeEdited.at (i) = tolower (tobeEdited.at (i));

} 
} 
 
int

main ()
{
  
 
 
stringManip S2 ("testing 123");
  
cout << "S2 before padString(20): <" << S2.retrieve () << ">" << endl;
  
cout << "S2 after padString(20): <" << S2.retrieve () << ">" << endl;
  
cout << "Should be: <testing 123       >" << endl << endl;
  
S2.center (21);
  
S2.size ();
  
cout << endl;
  
cout << "<" << S2.retrieve () << ">" << endl << endl;
  
return 0;

}

