//Name of the first input file: vehicles.txt
//Name of the second input file: rentals.txt

#include <iostream>
#include <vector>
#include "fstream"
#include "rental.h"
#include "Infile.h"
#include "Outfile.h"

using namespace std;

int main()
{
    //I. and II . reading available cars and buses from file into a vector
    vector<car> availableCars;
    vector<bus> availableBuses;

    Infile x("",1); // 1 to open files with cars/buses,2 to open files with rentals
    x.readCar();

    car itemC;


    if (x.End()) {
        cout << "empty file!\n";
    }
    else {
        while (!x.End()) {
            itemC=x.CurrentC();
            if(x.isCar()){
            availableCars.push_back(itemC);
            }
            else{
             bus itemB(itemC.get_nr_plate(),itemC.get_year(),itemC.get_fuel(),itemC.get_kms(),itemC.get_price(),x.get_capacity_int());
             availableBuses.push_back(itemB);
            }

            x.readCar();
        }
    }


    // III. reading rentals that took place this year into a vector
    vector<rental> rentedCars;
    vector<rental> rentedBuses;

    Infile y("",2); // 1 to open files with cars/buses,2 to open files with rentals
    y.readRental();


    if (y.End()) {
        cout << "empty file!\n";
    }
    else {
        while (!y.End()) {
            itemC=y.CurrentC();
            if(y.isCar()){
            rental rentC(y.get_sday(),y.get_eday(),itemC);
            rentedCars.push_back(rentC);
            }
            else{
             rental rentB(y.get_sday(),y.get_eday(),itemC,y.get_capacity_int());
             rentedBuses.push_back(rentB);
            }

            y.readRental();
        }
    }
    cout << endl;


    //IV. Show an example for the working of the following functions and operators
        cout << "Task IV." << endl << endl;
    //a) length_of_rental
        cout << "Start day of rental 1: " << rentedCars[0].get_s_day() << endl;
        cout << "End day of rental 1: " << rentedCars[0].get_e_day() << endl;
        cout << "Length of rental 1: " << rentedCars[0].length_of_rental() <<endl;
    //b) price of rental
        cout << "Price of rented car 1 per day: " << rentedCars[0].get_carR().get_price() << endl;
        cout << "Price of rental 1: " << rentedCars[0].price_of_rental() << endl;
    //c) operator+
        cout << rentedCars[0].get_carR().get_kms() << " km rented car run since it was assembled."<<endl;
        cout << rentedCars[0].get_carR().get_kms()+10 << " km - after running 10 km more." << endl << endl;


    //V. Tasks B & H
    cout << "Task V." << endl << endl;

    OutFile y1("length_of_car_rentals.txt");
    int MinPrice=0;
    string MinPriceNrPlate;
    for(int i=0;i<(int)rentedCars.size();i++){
        // B
        string s=rentedCars[i].get_carR().get_nr_plate();
        int d=rentedCars[i].length_of_rental();
        y1.writeCntRDays(s,d);

        // H
        if(rentedCars[i].price_of_rental()>MinPrice)
        {
            MinPrice=rentedCars[i].price_of_rental();
            MinPriceNrPlate=rentedCars[i].get_carR().get_nr_plate();

        }
    }
    cout << " h)" << endl << endl;;
    cout << "The car rental with car number plate " << MinPriceNrPlate << " cost the least." << endl;

    return 0;
}

//For error handling I "throw errors" in my setters and do not "catch errors" in my
// main program, since we assume that the input files are correct. And I think if will
// "catch error" my code will be messy.
