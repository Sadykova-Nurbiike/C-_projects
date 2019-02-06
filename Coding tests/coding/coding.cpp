#include "coding.h"
#include <fstream>
#include <cstdlib>
#include <string>

vector<ruleT> readrules(string inputfilename){
    vector<ruleT> rules;
    ruleT rule;

    ifstream f_in;
    f_in.open(inputfilename.c_str());
    if(f_in.is_open()){
        while(!f_in.eof()){
            f_in>>rule.to>>rule.from;
            rules.push_back(rule);
        }

        f_in.close();
    }
    else{cout<<"Can not open file."<<endl;}

    return rules;
    }


void readfile(string inputfilename, vector<string> &stringvector){
    string line;

    ifstream f_in;
    f_in.open(inputfilename.c_str());
    if(f_in.is_open()){
        while(!f_in.eof()){
            getline(f_in,line,'\n');
            stringvector.push_back(line);
        }

        f_in.close();
    }
    else{cout<<"Can not open file."<<endl;}
}


void decode(const vector<string> encoded, const vector <ruleT> rules, vector<string> &decoded){
    string line;

    for(unsigned int i=0;i<encoded.size();i++){
        line=encoded.at(i);
        for(unsigned int j=0;j<line.size();j++){
            for(unsigned int k=0;k<rules.size();k++){
                if(line[j]==rules[k].from){
                    line[j]=rules[k].to;
                }
            }
        }
        decoded.push_back(line);
    }
}


void writefile(string outputfilename, const vector<string> &stringvector){
    ofstream f_out(outputfilename.c_str());
    if(f_out.is_open()){
        for(unsigned int i=0;i<stringvector.size();i++){
            f_out<<stringvector.at(i)<<endl;
        }
        f_out.close();
    }
}



