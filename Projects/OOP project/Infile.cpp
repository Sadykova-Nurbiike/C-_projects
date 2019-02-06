#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "Infile.h"

using namespace std;

//constructor
Infile::Infile(string fname,int i)
{
    if ( fname.size()<1 ) {
        if(i==1){
        cout<< "Input file name of available cars/buses:" ;
        }
        else{
          cout<< "Input file name of the rentals that took place this year:";
        }
        cin>>fname;
    }
    bool error;
    do{
        error=false;
        f.open(fname.c_str());
        if ( f.fail() ){
            cout<< "There is no file with name \""<<fname<<"\" !\n"<<endl;
            error=true;
            char c;
            cout<<"Would you like to try again(y/n)"; cin>>c;
            if(c=='n') {
                cout<<"Goodbye!\n"; exit(2);
            }else{
                f.clear();
               if(i==1){
                cout<< "Input file name of available cars/buses:" ;
                }
                else{
                  cout<< "Input file name of the rentals that took place this year:";
                }
                cin>>fname;
            }
        }
    }while(error);
}

//function reads cars or buses from file
void Infile::readCar() {

    stringstream s;
    string line,tmps;
    float tmpf;
    int tmpi;
    getline(f,line);
    if (!f.fail()) {
        st=norm;
        s<<line;

        s>>iscar;
        s>>tmps; elementC.set_nr_plate(tmps);
        s>>tmpi; elementC.set_year(tmpi);
        s>>tmps;
        if(tmps=="gas") {elementC.set_fuel(gas);}
        else if(tmps=="diesel") {elementC.set_fuel(diesel);}
        else if (tmps=="hybrid"){elementC.set_fuel(hybrid);}
        else if (tmps=="electric"){elementC.set_fuel(electric);}
        s>>tmpf; elementC.set_kms(tmpf);
        s>>tmpi; elementC.set_price(tmpi);
        s>>capacity_int;
        // cout << "we read car!"<<endl;
    }
    else st=abnorm;
}

//function reads rentals from file
void Infile::readRental(){

    stringstream s;
    string line,tmps;
    float tmpf;
    int tmpi;
    getline(f,line);
    if (!f.fail()) {
        st=norm;
        s<<line;

        s>>iscar;
        s>>tmps; elementC.set_nr_plate(tmps);
        s>>tmpi; elementC.set_year(tmpi);
        s>>tmps;
        if(tmps=="gas") {elementC.set_fuel(gas);}
        else if(tmps=="diesel") {elementC.set_fuel(diesel);}
        else if (tmps=="hybrid"){elementC.set_fuel(hybrid);}
        else if (tmps=="electric"){elementC.set_fuel(electric);}
        s>>tmpf; elementC.set_kms(tmpf);
        s>>tmpi; elementC.set_price(tmpi);
        s>>capacity_int;
        s>>sday;
        s>>eday;
       // cout << "we read rental!"<<endl;
    }
    else st=abnorm;
}



