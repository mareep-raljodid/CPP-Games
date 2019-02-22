#include <iostream>
#include <cstring>
#include <cctype>
#include <math.h>
#include <iomanip>

using namespace std;

int randnum(int hh, int g){
    int rand_max=hh+1;
    int itr=g;
    int arrar[itr];
    int count[rand_max];
    int x=0, am=0, max=0, min=0, mean=0;
    float axx;
    
    for(int i=0; i<itr; i++){
        arrar[i]= rand()%rand_max;
        x = arrar[i];
        count[x]+=1;
    }
    
    for(int i=0; i<rand_max; i++){
        if(max<count[i])
            max=count[i];
    }
    min=max;
    for(int i=0; i<rand_max; i++){
        if(min>count[i])
            min=count[i];
    }
    
    cout<<"Index    Value     Bar"<<endl;
    for(int i=0; i<rand_max; i++){
        axx= (count[i]/20) ;
        cout<<setw(3)<<i<<setw(9)<<count[i]<<setw(9);
        am=0;
        while(am < ceil(axx)){
            cout<<"*";
            am++;
        }
        cout<<endl;
    }
    cout<<"Scale: "<<max/20<<endl;
    cout<<"Range: 0 to "<<hh<<endl;
    cout<<"Sample Count: "<<itr<<endl;
    cout<<"Min Value: "<<min<<endl;
    cout<<"Max Value: "<<max<<endl;
    cout<<"Sum Value: "<<itr<<endl;
    for(int i=0; i<rand_max; i++)
    {
        mean+=count[i];
    }
    float m=mean/(rand_max+1);
    cout<<"Mean Value: "<<m;
    
}

int main(){
  int a=0, b=0;
  cout<<"Enter End Range: "<<endl;
  cin>>a;
  cout<<"Enter number of Samples: "<<endl;
  cin>>b;
    randnum(a, b);
}
