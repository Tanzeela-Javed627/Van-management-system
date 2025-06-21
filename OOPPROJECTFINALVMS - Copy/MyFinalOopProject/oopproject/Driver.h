#pragma once
#include <string>
#include "BaseUser.h"
using namespace std;
// DRIVER INHERITING USER BASE
class Driver : public BaseUser {
	private:
     string LicenseNo;
     string TripStatus;
 	 int AssignedVanNo;
	public:
    // CONSTRUCTOR PARA
    Driver(string l, int v, string n, int i, char g, string c, string r);
    // DEFAULT CONSTRUCTOR
    Driver();
    // SETTERS AND GETTERS
    void SetterLicenseNo(string l);
    void SetterAssignedVanNo(int v);
    void SetterTripStatus(string s);
    string GetterLicenseNo() const;
    int GetterAssignedVanNo() const;
    string GetterTripStatus() const;
    /*  THE FOLLOWING FUNCTION HAS NO LINK TO THE LOGIC
    void DriChecker();*/
};
