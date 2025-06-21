#include<iostream>
#include<string>
#include"BaseUser.h"
using namespace std;

// PARA CONSTRUCTOR LOGIC
BaseUser::BaseUser(string n, int i, char g, string c, string r)
{
    Name = n;
    IdNo = i;
    Gender = g;
    ContactNum = c;
    Role = r;
}
//DEFAULT CONSTRUCTOR
BaseUser::BaseUser()
{
    Name = "UNNAMED";
    IdNo = 0000;
    Gender = 'X';
    ContactNum = 'XXX';
    Role = 'XX';
}

// SETTERS LOGIC
void BaseUser::SetterName(string n)
{
    Name = n;
}

void BaseUser::SetterContactNum(string n)
{
    ContactNum = n;
}

void BaseUser::SetterRole(string n)
{
    Role = n;
}

void BaseUser::SetterIdNo(int n)
{
    IdNo = n;
}

void BaseUser::SetterGender(char n)
{
    Gender = n;
}

// GETTERS LOGIC
string BaseUser::GetterName() const
{
    return Name;
}

string BaseUser::GetterContactNum() const
{
    return ContactNum;
}

string BaseUser::GetterRole() const
{
    return Role;
}

int BaseUser::GetterIdNo() const
{
    return IdNo;
}

char BaseUser::GetterGender() const
{
    return Gender;
}

/* THE FOLLOWING IS JUST FOR CHECKING NOT A PART OF ORIGINAL CODE WILL BE REMOVED
void BaseUser::Display() const
{
    cout << "Name: " << Name << endl;
    cout << "ID: " << IdNo << endl;
    cout << "Role: " << Role << endl;
    cout << "Gender: " << Gender << endl;
    cout << "Contact: " << ContactNum << endl;*/

