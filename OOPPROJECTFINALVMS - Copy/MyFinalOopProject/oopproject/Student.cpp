#include "Student.h"
#include <iostream>
using namespace std;
// //THE FOLLOWING IS THE CONSTRUCTOR
Student::Student(string p,string d,int v,string n, int i, char g, string c, string r) : BaseUser(n, i, g, c, r)   // I CALLED BASE USER CONSTRUCTOR HERE
{
    StuPickLoc=p;
    StuDropLoc=d;
    AssignedVanNo=v;
}
// DEFAULT
Student::Student(): BaseUser()
{
  //  cout<<"student construcntor is called";
    StuPickLoc="xxx";
    StuDropLoc="XXX";
    AssignedVanNo= 0;
}

// SETTERS
void Student::SetterSPL(string Pick)
{
    StuPickLoc = Pick;
}

void Student::SetterSDL(string Drop)
{
    StuDropLoc = Drop;
}

void Student::SetterAVN(int Van)
{
    AssignedVanNo = Van;
}

// GETTERS
string Student::GetterSPL() const
{
    return StuPickLoc;
}

string Student::GetterSDL() const
{
    return StuDropLoc;
}

int Student::GetterAVN() const
{
    return AssignedVanNo;
}
// LOGIC FOR WRITTING COMPLAINS
void Student::WriteComplain(){
    Complain c;
    c.WriteComplaint();
}
/* THE FOLLOWING IS JUST FOR CHECKING NOT LINKED WITH CODE LOGIC
void Student::Checker()
{
    cout<<"i am the syntax which will tell theat the student header file and student cppis running well"<<endl;*/
