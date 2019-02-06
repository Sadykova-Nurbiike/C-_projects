#ifndef NEWLIBRARY_H_INCLUDED
#define NEWLIBRARY_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct employee{
    string name;
    int age;
    string post;
    int salary;
};

void freadEmployees(string in_f_name,vector<employee> & data_);
int TaskA(vector<employee>  data_);
int TaskB(vector<employee>  data_);
int TaskC(vector<employee>  data_);


#endif // NEWLIBRARY_H_INCLUDED
