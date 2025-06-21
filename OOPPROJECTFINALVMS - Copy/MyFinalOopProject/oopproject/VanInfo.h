#pragma once
#include <string>
#include"TimeSlot.h"
using namespace std;
// THIS CLASS IS INDEPENDENT
class VanInfo {
	private:
 	     int VanNo;
      	 string Route;
         int Capacity;
         string DriverName;
         TimeSlot VanTime; // MADE A VARIABLE FOR THE ENUM TIMESLOT
	public:
         // CONSTRUCTOR
         VanInfo(int v, string r, int c, string d, TimeSlot t);
         // DEFAULT
         VanInfo();
         // SETTERS
         void SetterVanTime(TimeSlot t);
         void SetterVanNo(int v);
         void SetterRoute(string r);
         void SetterCapacity(int c);
         void SetterDriverName(string d);
          // GETTERS
         int GetterVanNo() const;
         string GetterRoute() const;
         TimeSlot GetterVanTime() const;
         int GetterCapacity() const;
         string GetterDriverName() const;
         // VIEWING VAN INFO
         void DisplayVanInfo() const;
         // THE FOLLOWING IS NOT THE PART OF THE LOGIC ITS A CHECKER
        // void VanInfoChecker();
};
