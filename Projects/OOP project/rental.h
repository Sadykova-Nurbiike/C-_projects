#ifndef RENTAL_H_INCLUDED
#define RENTAL_H_INCLUDED

#include <iostream>
#include "car.h"



class rental {
    private:
        int s_day;
        int e_day;
        car carR;
        int capacity;//for bus rentals
    public:
        //constructors
        rental(); //default constructor
        rental(int s,int e,car c);
        rental(int s,int e,car c,int cap);//for bus rentals;
        rental(int s,int e,std::string nr_p,int y,fuel_type f,float k,int p);
        //getters
        int get_s_day() const {return s_day;}
        int get_e_day() const {return e_day;}
        car get_carR() const {return carR;}
        int get_Rcapacity() const {return capacity;}
        //setters
        void set_s_day(int d);
        void set_e_day(int d);
        void set_carR(car c);
        void set_Rcapacity(int c);//for rental buses
        //member functions
        int length_of_rental() const;
        int price_of_rental() const;

};



#endif // RENTAL_H_INCLUDED
