#pragma once // PREVENTS UNKNOWN BUGS; TELLS THE COMPILER NOT TO CALL THE SAME HEADER FILE TWICE
#include <string>
using namespace std;

class BaseUser
{
    // THIS USER CLASS HAS PEOPLES INFO AS IT IS THE BASE CLASS.
    // WE WILL BE INHERITING FROM IT SO WE WILL USE PROTECTED ACCESS SPECIFIER
protected:
    string Name, ContactNum;
    string Role; // IE USER IS DRIVER OR STUDENT
    int IdNo; // ID NO IS CNIC NO
    char Gender;
public:
    BaseUser(string n, int i, char g, string c, string r); // CONSTRUCTOR DUMMY
    BaseUser();

    // I MADE GETTERS AND SETTERS TO ENSURE ENCAPSULATION
    // NAME GETTER SETTER
    void SetterName(string n);
    string GetterName() const; // This should match in both declaration and definition

    // CONTACTNUM GETTER SETTER
    void SetterContactNum(string n);
    string GetterContactNum() const; // This should match in both declaration and definition

    // ID GETTER SETTER
    void SetterIdNo(int n);
    int GetterIdNo() const;

    // GENDER GETTER SETTER
    void SetterGender(char n);
    char GetterGender() const;

    // ROLE GETTER SETTER
    void SetterRole(string n);
    string GetterRole() const;

    // CHECKING FUNCTION
    //void Display() const;
};
