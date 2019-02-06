#include "car.h"
#include <iomanip>

using namespace std;

//constructors
car::car(): nr_plate(""),year(0),fuel(ND),kms(0),price(0){}

car::car(string nr_p,int y,fuel_type f,float k,int p){
    nr_plate=nr_p;
    year=y;
    if(!(f==gas || f==diesel || f==hybrid || f==electric)){
        throw WrongFuelType;
    }
    else {fuel=f;}

    if(k<0 or p<0){
        throw WrongInput;
    }
    else{
    kms=k; price=p;
    }
}

//setters
void car::set_nr_plate(std::string nr_p){
    nr_plate=nr_p;
}

void car::set_year(int y){
    year=y;
}

void car::set_fuel(fuel_type f){
    if(!(f==gas || f==diesel || f==hybrid || f==electric)){
        throw WrongFuelType;
    }
    else {fuel=f;}
}

void car::set_kms(float k){
    if(k<0 ){
        throw WrongInput;
    }
    else{
    kms=k;
    }
}

void car::set_price(int p){
    if(p<0){
        throw WrongInput;
    }
    else{
    price=p;
    }
}

//operator overloading
void car::operator+(const float k) {
    float tmp=get_kms()+k;
    set_kms(tmp);
}



