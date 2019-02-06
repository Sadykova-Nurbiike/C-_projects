#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "newLibrary.h"

string inFileName="sampleIn.txt";
string outFileName="sampleOut.txt";
vector<employee> data_Emp;


using namespace std;

int main()
{
    //read from a file
    freadEmployees(inFileName,data_Emp);

    //Output file
    ofstream fout(outFileName.c_str());


    //Task A: The index of the youngest employee
    int Ind=TaskA(data_Emp);
    fout <<"The index of the youngest employee: " << Ind+1 << "." << endl;

    //Task B: How many employees whose is age over 30 have a salary under 150000HUF?
    int cntB=TaskB(data_Emp);
    fout << "Number of employees who are 30+ years old and have salary under 150000HUF : "<< cntB << endl;


    //Task C: How many different ages can you find at the company?
    int cntC=TaskC(data_Emp);
    fout << "Number of different ages: " << cntC << endl;

    fout.close();

    return 0;
}
