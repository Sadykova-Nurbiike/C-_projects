//Neptun-code: M1YVEQ
//Name: Sadykova Nurbiike

#include <iostream>
#include "coding.h"

using namespace std;

int main()
{
    string inputfile1="rules.txt";
    string inputfile2="strings.txt";
    string outputfile="decodedstrings.txt";
    vector<ruleT> codingrules;
    vector<string> codedstrings;
    vector<string> decodedstrings;

    codingrules=readrules(inputfile1);
    readfile(inputfile2,codedstrings);

    decode(codedstrings,codingrules,decodedstrings);

    writefile(outputfile,decodedstrings);


    return 0;
}
