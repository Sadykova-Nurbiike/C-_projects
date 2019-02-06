#include "Outfile.h"
#include <iostream>
#include <iomanip>

//constructor
OutFile::OutFile(const std::string& filename) {
    f.open(filename.c_str());
    if (f.fail()) {
        std::cerr << filename << " was not created!\n";
    }
    else {
        f << std::setw(20) << "Number plate of car" << std::setw(20) << "Length of rental"<<  std::endl;
    }
}

//function writes number plate and number of days car was rented out
void OutFile::writeCntRDays(const std::string &s,const int &d){
    f << std::setw(20) << s << std::setw(20) << d <<  std::endl;
}
