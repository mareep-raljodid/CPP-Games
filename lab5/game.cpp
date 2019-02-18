#include <cstdlib>
#include <ctime>
#include<iostream>

using namespace std;
int input(){
    int y=0;
    cout<<"Enter your point value (1 - 6): ";
    
yup:
    cin>>y;
    if(y<1 || y>6){
        cout<<"Error: Enter your point value, must be between 1 and 6: ";
        goto yup;}
    return y;
}

int rollDie() {
    int t;
    t=rand()%6+1;
    cout<<"You Rolled: "<<t<<endl;
    
    return t;}

bool playOneGame(int r){
    if(r==rollDie())
        return true;
    else
        return false;
}

int main(){
    
    srand(time(nullptr));
    int temp, f=0;
    bool rp;
    int wager, bal=100;
    cout<<"Account balance $100"<<endl;
    cout<<"Enter wager (0 to exit): ";
top:
    cin>>temp;
    if(temp>bal){
        cout<<"Error: You must wager between $1 and $100 (type 0 to exit): ";
        goto top;
    }
    else {
        wager=temp;
    }
fml:
    cout<<endl;
    cout<<endl;
    int e= input();
    f=0;
    while(f<3){
        if(wager>0){
            rp = playOneGame(e);
            if(rp==true){
                bal=bal+wager;
                cout<<" ** You win! **"<<endl;
                cout<<"Account balance $"<<bal<<endl;
                break;}
            else if(rp==false){
                f++;}
            else if(wager==0)
                break;}
    }
    if(f>=3){
        bal=bal-wager;
        cout<<" ** You Lose **"<<endl;
        cout<<"Account balance $"<<bal<<endl;}
    if(bal==0){
        cout<<"Game over, you are out of money!"<<endl;
        cout<<"Your final account balance is $0"<<endl;}
    else{
        cout<<"Enter wager (0 to exit): ";
        cin>>wager;
        if((wager!=0) && (wager<=bal))
            goto fml;
        else if(wager==0)
            cout<<"Your final account balance is $"<<bal<<endl;
        else {
            cout<<"Enter wager once more please: ";
            goto top;
        }
    }
}
