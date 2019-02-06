#ifndef INFILE_H_INCLUDED
#define INFILE_H_INCLUDED
#include <fstream>
#include "rental.h"

enum Status{abnorm, norm};

class Infile{
public:
    //constructor
    Infile(std::string fname="",int i=1);
    //destructor
    ~Infile() {f.close();}
    //getters
    int get_capacity_int() const {return capacity_int;}
    int get_sday() const {return sday;}
    int get_eday() const {return eday;}
    //functions
    void readCar();
    void readRental();
    car CurrentC() const {return elementC;}
    bool End() const {return st==abnorm;}
    bool isCar() const {return iscar=="car";}
private:
    std::ifstream f;
    std::string iscar;
    int capacity_int,sday,eday;
    car elementC;
    Status st;
};


#endif // INFILE_H_INCLUDED
