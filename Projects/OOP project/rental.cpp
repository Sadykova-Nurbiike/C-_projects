#include "rental.h"
#include <iomanip>

using namespace std;

//constructors
rental::rental():s_day(0),e_day(0),carR(){}

rental::rental(int s,int e,car c){
    s_day=s;
    if(s>e){throw WrongEndDay;}
    else{e_day=e;}
    carR=c;
}

rental::rental(int s,int e,car c,int cap){
    s_day=s;
    if(s>e){throw WrongEndDay;}
    else{e_day=e;}
    carR=c;
    capacity=cap;
}

rental::rental(int s,int e,string nr_p,int y,fuel_type f,float k,int p){
    s_day=s;
    if(s>e){throw WrongEndDay;}
    else{e_day=e;}
    car(nr_p,y,f,k,p);
}

//setters
void rental::set_s_day(int d){
    s_day=d;
}

void rental::set_e_day(int d){
    if(s_day>d){throw WrongEndDay;}
    else{e_day=d;}
}

void rental::set_carR(car c){
    carR=c;
}

void rental::set_Rcapacity(int c){
    capacity=c;
}

//member functions
int rental::length_of_rental() const {
    return (e_day-s_day);
}

int rental::price_of_rental() const{
    return (length_of_rental()*carR.get_price());
}




