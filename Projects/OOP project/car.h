#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <iostream>

enum fuel_type {gas,diesel,hybrid,electric,ND};

enum errors {WrongFuelType,WrongInput,WrongEndDay};

class car {
    protected:
        std::string nr_plate;
        int year;
        fuel_type fuel;
        float kms;
        int price;
    public:
        //constructors
        car();
        car(std::string nr_p,int y,fuel_type f,float k,int p);
        //getters
        std::string get_nr_plate() const {return nr_plate;}
        int get_year() const {return year;}
        fuel_type get_fuel() const {return fuel;}
        float get_kms() const {return kms;}
        int get_price() const {return price;}
        //setters
        void set_nr_plate(std::string nr_p);
        void set_year(int y);
        void set_fuel(fuel_type f);
        void set_kms(float k);
        void set_price(int p);
        //operator overloading
        void operator+(const float k);
};

class bus : public car {
    protected:
        int capacity;
    public:
        //constructor(s)
        bus():capacity(0){}
        bus(std::string nr_p,int y,fuel_type f,float k,int p,int c){
            nr_plate=nr_p;
            year=y;
            if(!(f==gas || f==diesel || f==hybrid || f==electric)){
                 throw WrongFuelType;
            }
            else {fuel=f;}

            if(k<0 or p<0 or c<0){
                throw WrongInput;
            }
            else{
                kms=k; price=p;capacity=c;
            }
        }
        //getters
        int get_capacity() const {return capacity;}
        //setters
        void set_capacity(int c){
            if(c<0 ){throw WrongInput;}
            else{capacity=c;}
        }

};


#endif // CAR_H_INCLUDED
