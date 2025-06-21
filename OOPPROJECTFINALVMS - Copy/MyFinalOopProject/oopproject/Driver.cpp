#pragma once
#include "Driver.h"
#include <iostream>
using namespace std;
// CONSTRUCTOR
Driver::Driver(string l, int v, string n, int i, char g, string c, string r) : BaseUser(n, i, g, c, r) {// CALLED BASE CLASS CONSTRUCTOR
    LicenseNo = l;
    AssignedVanNo = v;
    TripStatus = "notstarted\n";
}
//DEFAULT
Driver::Driver(): BaseUser(){
   // cout<<"driver constructor is running";
    LicenseNo = "XXX";
    AssignedVanNo = 000;
    TripStatus = "notstarted\n";
}
    // SETTERS
    void Driver::SetterLicenseNo(string l) {
    LicenseNo = l;
}
    void Driver::SetterAssignedVanNo(int v) {
    AssignedVanNo = v;
}
    void Driver::SetterTripStatus(string s) {
    TripStatus = s;
}
    // GETTERS
    string Driver::GetterLicenseNo() const {
    return LicenseNo;
}
    int Driver::GetterAssignedVanNo() const {
    return AssignedVanNo;
}
    string Driver::GetterTripStatus() const {
    return TripStatus;
}
    /*  THE FOLLOWING FUNCTION HAS NO LINK TO THE LOGIC
    void Driver::DriChecker(){
    cout<<"driver checker is runninfg";}*/

