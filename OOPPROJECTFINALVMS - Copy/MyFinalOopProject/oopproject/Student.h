#pragma once
#include<string>
#include"BaseUser.h"
#include"Complain.h"
using namespace std;
class Student : public BaseUser
{
private:
    string StuPickLoc;
    string StuDropLoc;
    int AssignedVanNo;
public:
    // PARACONSTRUCTOR
    Student(string p,string d,int v,string n, int i, char g, string c, string r);
    // DEFAULT CONSTRUCTOR
    Student();
    // GETTERS AND SETTERS
    void SetterSPL(string Pick);
    string GetterSPL() const;
    void SetterSDL(string Drop);
    string GetterSDL () const;
    void SetterAVN(int Van);
    int GetterAVN () const;
    // FUNCTION FOR WRITING COMPLAINS
    void WriteComplain();
    // THE FOLLOWING FUNCTION IS NOT LINKED WITH ACTUAL CODE ITS JUST FOR CHECKING
    // void Checker();
};
