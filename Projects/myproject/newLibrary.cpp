#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include "newLibrary.h"


void freadEmployees(string in_f_name,vector<employee> & data_){
     string tmp, tmp2;
     size_t pos;
     employee tmpEmployee;

     ifstream fin;
     fin.open(in_f_name.c_str());

     if(fin.is_open()){
            while(getline(fin,tmp,'\n')){
            //find first item until ';'
            pos=tmp.find(';');
            tmp2=tmp.substr(0,pos);
            tmpEmployee.name=tmp2;
            tmp=tmp.substr(pos+1);

            //find second item until ';'
            pos=tmp.find(';');
            tmp2=tmp.substr(0,pos);
            tmpEmployee.age=atoi(tmp2.c_str());
            tmp=tmp.substr(pos+1);

            //find third item until ';'
            pos=tmp.find(';');
            tmp2=tmp.substr(0,pos);
            tmpEmployee.post=tmp2;
            tmp=tmp.substr(pos+1);

            //item four
            tmpEmployee.salary=atoi(tmp.c_str());

            //add tmpEmployee to vector data_
            data_.push_back(tmpEmployee);
            }

        fin.close();
     }

}


int TaskA(vector<employee>  data_){
    int Min=0;
    int MinAge=data_.at(0).age;
    for(unsigned int i=0;i<data_.size();i++){
        if(data_[i].age<MinAge){
            MinAge=data_[i].age;
            Min=i;
        }
    }

    return Min;
}

int TaskB(vector<employee>  data_){
    int cnt=0;
    for(unsigned int i=0;i<data_.size();i++){
        if(data_[i].age>30 && data_[i].salary<150000){
            cnt++;
        }
    }

    return cnt;
}


int TaskC(vector<employee>  data_){
    int cnt;
    for(unsigned int j=0;j<data_.size()-1;j++){
            unsigned int i=j+1;
            while(i<data_.size()){
                if(data_[j].age==data_[i].age){
                    data_.erase(data_.begin()+i);
                }
                else{i++;}
            }
        }
    cnt=data_.size();

    return cnt;
}
