#include "VanInfo.h"
#include <iostream>
using namespace std;
// CONSTRUCTOR
VanInfo::VanInfo(int v, string r, int c, string d, TimeSlot t) {
         VanNo = v;
         Route = r;
         Capacity = c;
         DriverName = d;
         VanTime = t;
}
// DEFAULT
VanInfo::VanInfo(){
         VanNo = 000;
         Route = "XXX";
         Capacity = 000;
         DriverName = "XXX";
         VanTime = TimeSlot::Default;
}
     // SETTERS
     void VanInfo::SetterVanNo(int v) {
     VanNo = v;
}
     void VanInfo::SetterVanTime(TimeSlot t) {
     VanTime = t;
}
     void VanInfo::SetterRoute(string r) {
     Route = r;
}
     void VanInfo::SetterCapacity(int c) {
     Capacity = c;
}
     void VanInfo::SetterDriverName(string d) {
     DriverName = d;
}
     // GETTERS
     int VanInfo::GetterVanNo() const {
     return VanNo;
}
     string VanInfo::GetterRoute() const {
     return Route;
}
     TimeSlot VanInfo::GetterVanTime() const {
     return VanTime;
}
     int VanInfo::GetterCapacity() const {
     return Capacity;
}
     string VanInfo::GetterDriverName() const {
     return DriverName;
}
     // FUNCTION TO DISPLAY VAN INFO
     void VanInfo::DisplayVanInfo() const {
     cout << "Van No: " << VanNo << endl;
     cout << "Route: " << Route << endl;
     cout << "Capacity: " << Capacity << endl;
     cout << "Driver Name: " << DriverName << endl;
     cout << "Time Slot: ";
    switch (VanTime) {// FOR DISPLAYING VAN TIME
        case TimeSlot::Morning: cout << "Morning"; break;
        case TimeSlot::Afternoon: cout << "Afternoon"; break;
        case TimeSlot::Evening: cout << "Evening"; break;
        default: cout << "Unknown";
    }
     }
    // THE FOLLOWING IS NOT THE PART OF THE LOGIC ITS A CHECKER
   //  void VanInfo::VanInfoChecker(){
    // cout<<"van info class and header are working";}
