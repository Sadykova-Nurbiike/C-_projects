#ifndef OUTFILE_H_INCLUDED
#define OUTFILE_H_INCLUDED

#include "rental.h"
#include <fstream>
#include <string>

class OutFile{
    private:
        std::ofstream f;
    public:
        //constructor
        OutFile(const std::string& filename);
        //destructor
        ~OutFile() {f.close();}
        //function
        void writeCntRDays(const std::string &s,const int &d);
};



#endif // OUTFILE_H_INCLUDED
