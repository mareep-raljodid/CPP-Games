//This program was brutal, took me 6 straight hours to do it.
//It was literal busywork, overall a good program to code, 
//but, if there is a program even remotely work intensive as this, please, a heads-up for future labs would be great.
//Although, you might enjoy my program. 




#include<cmath>
#include <iostream>
#include <iomanip>
using namespace std;

double hulu, r, l, c, a, f=50, omeg= 3.15159*2*f, eo, t, n, ddyy=0;


double v(double t){
    double god= eo * sin(omeg * t);
    return god;
    
}
double amp(){
    double help_me=  (omeg * eo)/ (sqrt(pow((l*pow(omeg,2)-(1/c)),2)+(pow(r,2)*pow(omeg,2))));
    return help_me;
}
double angle_phase(){
    double this_program_sux= atan(((l*omeg)/r)-(1/(r*c*omeg)));
    return this_program_sux;
}
double i(double t){
    double my_life_sucks=amp()*sin(omeg* t - angle_phase());
    return my_life_sucks;
}
double vd_resistor(double t){
    double i_m_stuck_in_college=r*amp()*sin(omeg*t-angle_phase());
    return i_m_stuck_in_college;
}
double vd_inductor(double t){
    double theres_no_way_out=l*omeg*amp()*cos(omeg*t-angle_phase());
    return theres_no_way_out;
}
double vd_capacitor(double t){
    double this_program_is_still_not_over=(-1 * amp() * cos(omeg*t-angle_phase()))/(c*omeg);
    return this_program_is_still_not_over;
}


int main() {
    
    cout<<"Please Input:"<<endl;
    cout<<"Applied voltage amplitude (Eo)";
    cin>>eo;
    cout<<endl;
    cout<<"Line frequency (f)";
    cin>>f;
    cout<<endl;
    cout<<"Resistor value (R)";
    cin>>r;
    cout<<endl;
    cout<<"Inductor value (L)";
    cin>>l;
    cout<<endl;
    cout<<"Capacitor value (C)";
    cin>>c;
    cout<<endl;
    cout<<"pts/AC period (nstep)";
    cin>>n;
    cout<<endl;
    double tx=(1/f);
    t=tx/n;
    
    
    
    cout<<"RLC Circuit Summary:"<<endl;
    cout<<endl;
    //double raj=  (omeg * eo)/ (sqrt(pow((l*pow(omeg,2)-(1/c)),2)+(pow(r,2)*pow(omeg,2))));
    cout<<"Voltage: "<<eo<<"-Volts @ "<<f<<"-Hz"<<endl;
    cout<<"Resistor Value: "<<r<<"-ohms"<<endl;
    cout<<"Inductor Value: "<<l<<"-H"<<endl;
    cout<<"Capacitor Value: "<<c<<"-F"<<endl;
    cout<<"nsteps: "<<n<<endl;
    cout<<"Calculated Parameters:"<<endl;
    cout<<"Current Amplitude:       "<<amp()<<"-amps"<<endl;
    cout<<"Phase Angle:         "<<angle_phase()<<"-degrees"<<endl;
    cout<<"Iteration"<<setw(30)<<"Time"<<setw(30)<<"AV"<<setw(30)<<"I"<<setw(30)<<"VR"<<setw(30)<<"VL"<<setw(30)<<"VC"<<setw(30)<<"VT"<<setw(30)<<"Vdiff"<<endl;
    
    for(double vr=0.000; vr<=n; vr+=t){
        int iopc=vr*1000;
        cout<<iopc<<setw(30)<<std::setprecision(5)<<vr<<setw(30)<<v(vr)<<setw(30)<<i(vr)<<setw(30)<<vd_resistor(vr)<<setw(30)<<vd_inductor(vr)<<setw(30)<<vd_capacitor(vr)<<setw(30)<<v(vr)<<setw(30)<<v(vr)-(vd_resistor(vr)+vd_inductor(vr)+vd_capacitor(vr))<<endl;
    }
}
//I'm free now!! It's finally over!
//I can have have 3 hours and 5 minutes of sleep now, yay!
