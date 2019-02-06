//Name: Sadykova Nurbiike
//Neptune code: M1YVEQ
/*
%% <Name>
%% <Neptun ID>
%% <Subject & Assignment name>
%% <Submission date>
%% This solution was submitted and prepared by
%% <Name, Neptun ID> for the Lab Coding Test of the Programming Fundamentals course.
%% I declare that this solution is my own work.
%% I have not copied or used third party solutions.
%% I have not passed my solution to my classmates, neither  made it public.
%% Students' regulation of Eotvos Lorand University (ELTE Regulations Vol. II. 74/C. § )
%% states that as long as a student presents another student's work - or at least the significant part of it - as their own
%% performance, it will count as a disciplinary fault. The most serious consequence of a disciplinary fault
%% can be dismissal of the student from the University.
*/

#include <iostream>

using namespace std;

int main()
{

   int exams;
    bool error;
    string tmp;
    do{
        cout << "How many exams did a student write: ";cin>>exams;
        error = ( cin.fail() || cin.peek()!='\n' || (exams<1) || (exams>8));
        if(error){
            cout << "Please, enter an integer between 1 and 8 (including).\n";
            cin.clear();
            getline(cin,tmp,'\n');
        }
    }while(error);

    int grades[exams];
    for(int i=0;i<exams;i++){
    do{
        cout <<"Grade of exam "<<i+1<<": "<<endl;cin>>grades[i];
        error = ( cin.fail() || cin.peek()!='\n' || (grades[i]<1) || (grades[i]>5) );
        if(error){
            cout << "Invalid grade. Grade can be an integer between 1 and 5 (including).\n";
            cin.clear();
            getline(cin,tmp,'\n');
        }
    }while(error);
    }

    //problem A
    int sum=0;
    for(int i=0;i<exams;i++){
        sum=sum+grades[i];
        }
    int average=sum/exams;
    bool certificate=(average>=2);
    if(certificate){
        cout << "He will get a certificate."<<endl;
    }
    else{
        cout << "Unfortunately, he won't get a certificate."<<endl;
    }


    //problem B
    bool existsfive;

    int i=0;
    while ((i<exams) && (grades[i]!=5)) {
        i=i+1;
    }
    existsfive=(i<exams);
    if (existsfive) {
        cout << "He got 5 for at least one exam." << endl;
    }
    else {cout << "He did not get 5 for at least one exam.";}

    return 0;
}
