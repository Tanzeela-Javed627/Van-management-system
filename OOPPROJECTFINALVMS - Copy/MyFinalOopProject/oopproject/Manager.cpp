#include "Manager.h"
#include <iostream>
using namespace std;
// CONSTRUCTOR
Manager::Manager() : BaseUser () {}
Manager::Manager(string n, int i, char g, string c, string r) : BaseUser(n, i, g, c, r) {}//USING BASE CLASS CONSTRUCTOR THIS IS ONLY WHERE INHERITANCE IS USED
// AS MANAGER IS CONTROLLING EVERYTHING LIKE STUDENT, DRIVER, VANINFO, COMPLAINT WE WILL WRITE THE LOGIC FOR EACH ONE BY ONE

// FOR STUDENT

// LOGIC FOR ADDING STUDENT
	void Manager::AddStu() {
	// DECLARING INFO OF THE STUDENT THAT IS NEEDED
    string Name, Contact, PickLoc, DropLoc;
    int Id, VanNo;
    char Gender;
    // ENTERING THESE INFO
    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, Name);
    cout << "Enter Student ID: ";
    cin >> Id;
    cout << "Enter Gender (M/F): ";
    cin >> Gender;
    cout << "Enter Contact Number: ";
    cin.ignore();
    getline(cin, Contact);
    cout << "Enter Pickup Location: ";
    getline(cin, PickLoc);
    cout << "Enter Drop Location: ";
    getline(cin, DropLoc);
    cout << "Enter Assigned Van Number: ";
    cin >> VanNo;
    // MAKING AN OBJECT OF STUDENT
    //LINKING THE VARIABLES MADE ABOVE WITH THE SETTERS OF OTHER CLASSES
    Student s;
    // USING BASE USER SETTERS AND GETTERS COMPOSITION OOP CONCEPT
    s.SetterName(Name);
    s.SetterIdNo(Id);
    s.SetterGender(Gender);
    s.SetterContactNum(Contact);
    s.SetterRole("Student");
     // USING STUDENT SETTERS AND GETTERS OOP CONCEPT COMPOSITION
    s.SetterSPL(PickLoc);
    s.SetterSDL(DropLoc);
    s.SetterAVN(VanNo);
    // Add THE OBJECT S OF STUDENT CLASS TO THE VECTOR OF STUDENTS WE CREATED IN MANAGER.H
    Students.push_back(s);
    cout << "\nStudent is added successfully!!!\n";
}
// LOGIC FOR DELETILG STUDENT
void Manager::DelStu() {
    int IdToDelete;
    cout << "Enter the ID of the student you want to delete: ";
    cin >> IdToDelete;
    bool found = false;// BOOL IS FALSE BCS WE ARE ASSUMING THAT STUDENT IS NOT FOUNG
    // FOR LOOP TO ITERATE THROUGH THE STUDENT VECTOR
    for (int i = 0; i < Students.size(); i++) {//.SIZE IS BUILT IN IN VECTORS
        if (Students[i].GetterIdNo() == IdToDelete) {// GETTERIDNO IS FROM PARENT CLASS
            Students.erase(Students.begin() + i);// .ERASE DONT ERASE A VALUE IT ERASES A POSITION THATS WHY WE TOLD THE COMPILER TO ERASE THE STUDENT WHO IS I STEPS AWAY FROM THE BEGGINING
            cout << "Student with ID " << IdToDelete << " has been deleted successfully. "<<endl;
            found = true;// SO THAT THE LOOP STOPS
            break;
        }
    }

    if (!found) {// IE IF FOUND IS STILL FALSE AND THA ARRAY ENDED THEN TELL THE USER TO SHUTUP
        cout << "No student found with ID " << IdToDelete << endl;
    }
}

// LOGIC FOR ASSIGNING STUDENT TO VAN

void Manager::AssignStu() {
    int StudentId, VanNo;
    bool StudentFound = false;
    cout << "Enter Student ID to assign: ";
    cin >> StudentId;
    // LOOPING THROUGH STUDENTS TO FIND THE STUDENT
    for (int i = 0; i < Students.size(); i++) {
        if (Students[i].GetterIdNo() == StudentId) { // FINDING STUDENT BY ID
            StudentFound = true;
            cout << "Enter Van Number to assign to Student: ";
            cin >> VanNo;
            // CHECKING IF VAN EXISTS IN VECTOR
            bool VanExists = false;
            for (int j = 0; j < Vans.size(); j++) {
                if (Vans[j].GetterVanNo() == VanNo) {
                    VanExists = true;
                    break;
                }
            }
            if (!VanExists) {
                cout << "Van with number " << VanNo << " does not exist.\n";
                return;
            }
            // FINALLY ASSIGNING VAN TO STUDENT
            Students[i].SetterAVN(VanNo);
            cout << "Student assigned to Van " << VanNo << " successfully." << endl;
            return;
        }
    }

    if (!StudentFound) { // IF STUDENT NOT FOUND
        cout << "No student found with ID " << StudentId << endl;
    }
}
// LOGIC FOR VIEWING ASSIGNED VAN DETAILS FOR A STUDENT
void Manager::ShowAssignedVanToStudent() {
    int StudentId;
    cout << "Enter your Student ID: ";
    cin >> StudentId;
    bool StudentFound = false;

    // LOOP THROUGH STUDENTS TO MATCH ID
    for (int i = 0; i < Students.size(); i++) {
        if (Students[i].GetterIdNo() == StudentId) {
            StudentFound = true;
            int AssignedVanNo = Students[i].GetterAVN(); // GETTING ASSIGNED VAN NO

            // LOOPING THROUGH VAN VECTOR TO FIND THE MATCHING VAN
            for (int j = 0; j < Vans.size(); j++) {
                if (Vans[j].GetterVanNo() == AssignedVanNo) {
                    cout << "\nVan Details for Student ID " << StudentId << ":\n";
                    cout << "Van No: " << Vans[j].GetterVanNo() << endl;
                    cout << "Driver Name: " << Vans[j].GetterDriverName() << endl;
                    cout << "Route: " << Vans[j].GetterRoute() << endl;
                    cout << "Capacity: " << Vans[j].GetterCapacity() << endl;
                    return;
                }
            }
            // IF VAN NOT FOUND BUT STUDENT EXISTS
            cout << "Assigned van not found in the system.\n";
            return;
        }
    }

    if (!StudentFound) {
        cout << "No student found with ID " << StudentId << endl;
    }
}
// LOGIC FOR VIEWING STUDENT COMPLAINS
void Manager::ViewComplain() {
    Complain C; // CREATING AN OBJECT FOR THE COMPLAIN
    C.ReadComplaints();// CALLS THE CLASS METHOD OF READING COMPLAINS
}


// FOR DRIVER

// LOGIC FOR ADDING DRIVER

void Manager::AddDri() {
    // DECLARING INFO OF THE DRIVER THAT IS NEEDED
    string Name, Contact, LicenseNo;
    int Id, VanNo;
    char Gender;

    // ENTERING THESE INFO
    cout << "Enter Driver Name: ";
    cin.ignore();
    getline(cin, Name);
    cout << "Enter Driver ID: ";
    cin >> Id;
    cout << "Enter Gender (M/F): ";
    cin >> Gender;
    cout << "Enter Contact Number: ";
    cin.ignore();
    getline(cin, Contact);
    cout << "Enter License Number: ";
    getline(cin, LicenseNo);
    cout << "Enter Assigned Van Number: ";
    cin >> VanNo;

    // CREATING DRIVER OBJECT
    Driver d;

    // USING BASE CLASS SETTERS
    d.SetterName(Name);
    d.SetterIdNo(Id);
    d.SetterGender(Gender);
    d.SetterContactNum(Contact);
    d.SetterRole("Driver");

    // USING DRIVER CLASS SETTERS
    d.SetterLicenseNo(LicenseNo);
    d.SetterAssignedVanNo(VanNo);

    // ADDING DRIVER OBJECT TO VECTOR
    Drivers.push_back(d);
    cout << "\nDriver added successfully!!!\n";
}

// LOGIC FOR DELETING DRIVER

void Manager::DelDri() {
    int IdToDelete;
    cout << "Enter the ID of the driver you want to delete: ";
    cin >> IdToDelete;
    bool found = false; // BOOL IS FALSE BCS WE ARE ASSUMING THAT DRIVER IS NOT FOUND

    // FOR LOOP TO ITERATE THROUGH THE DRIVER VECTOR
    for (int i = 0; i < Drivers.size(); i++) { //.SIZE IS BUILT IN IN VECTORS
        if (Drivers[i].GetterIdNo() == IdToDelete) { // GEETERIDNO IS FROM PARENT CLASS
            Drivers.erase(Drivers.begin() + i); // .ERASE DONT ERASE A VALUE IT ERASES A POSITION THATS WHY WE TOLD THE COMPILER TO ERASE THE DRIVER WHO IS I STEPS AWAY FROM THE BEGGINING
            cout << "Driver with ID " << IdToDelete << " has been deleted successfully. " << endl;
            found = true; // SO THAT THE LOOP STOPS
            break;
        }
    }

    if (!found) { // IE IF FOUND IS STILL FALSE AND THA ARRAY ENDED THEN TELL THE USER TO SHUTUP
        cout << "No driver found with ID " << IdToDelete << endl;
    }
}

// LODIC FOR ASSIGNING VAN TO DRIVER

void Manager::AssignDri() {
    int DriverId, VanNo;
    bool DriverFound = false;

    cout << "Enter Driver ID to assign: ";
    cin >> DriverId;

    // LOOPING THROUGH DRIVERS TO FIND THE DRIVER
    for (int i = 0; i < Drivers.size(); i++) {
        if (Drivers[i].GetterIdNo() == DriverId) {
            DriverFound = true;
            cout << "Enter Van Number to assign to Driver: ";
            cin >> VanNo;
            // CHECKING IF VAN EXISTS
            bool VanExists = false;
            for (int j = 0; j < Vans.size(); j++) {
                if (Vans[j].GetterVanNo() == VanNo) {
                    VanExists = true;
                    break;
                }
            }

            if (!VanExists) {
                cout << "Van with number " << VanNo << " does not exist.\n";
                return;
            }
            // FINALLY ASSIGNING VAN TO DRIVER
            Drivers[i].SetterAssignedVanNo(VanNo);
            cout << "Driver assigned to Van " << VanNo << " successfully. " <<endl;
            return;
        }
    }

    if (!DriverFound) {
        cout << "No driver found with ID " << DriverId << endl;
    }
}

// LOGIC FOR VIEWING ASSIGNED VAN DETAILS FOR A DRIVER
void Manager::ShowAssignedVanToDriver() {
    int DriverId;
    cout << "Enter your Driver ID: ";
    cin >> DriverId;
    bool DriverFound = false;

    // LOOP THROUGH DRIVERS TO MATCH ID
    for (int i = 0; i < Drivers.size(); i++) {
        if (Drivers[i].GetterIdNo() == DriverId) {
            DriverFound = true;
            int AssignedVanNo = Drivers[i].GetterAssignedVanNo(); // GETTING ASSIGNED VAN NO

            // LOOPING THROUGH VAN VECTOR TO FIND THE MATCHING VAN
            for (int j = 0; j < Vans.size(); j++) {
                if (Vans[j].GetterVanNo() == AssignedVanNo) {
                    cout << "\nVan Details for Driver ID " << DriverId << ":\n";
                    cout << "Van No: " << Vans[j].GetterVanNo() << endl;
                    cout << "Driver Name: " << Vans[j].GetterDriverName() << endl;
                    cout << "Route: " << Vans[j].GetterRoute() << endl;
                    cout << "Capacity: " << Vans[j].GetterCapacity() << endl;
                    return;
                }
            }
            // IF VAN NOT FOUND BUT DRIVER EXISTS
            cout << "Assigned van not found in the system.\n";
            return;
        }
    }

    if (!DriverFound) {
        cout << "No driver found with ID " << DriverId << endl;
    }
}

// FOR VAN INFO

// LOGIC FOR ADDING VAN
void Manager::AddVan() {
    // DECLARING INFO THAT IS NEEDED FOR VAN
    string DriverName, Route;
    int VanNo, Capacity;
    // ENTERING THESE INFO
    cout << "Enter Van Number: ";
    cin>> VanNo;
    cin.ignore(); // TO AVOID CIN SKIP BUG
    cout << "Enter Driver Name for this Van: ";
    getline(cin, DriverName);
    cout << "Enter Route for the Van: ";
    getline(cin, Route);
    cout << "Enter Capacity of the Van: ";
    cin >> Capacity;
    // CREATING VAN OBJECT USING PARAMETERIZED CONSTRUCTOR
    VanInfo v;
    //v.SetterVanTime(TimeSlot t);
    v.SetterVanNo(VanNo);
    v.SetterRoute(Route);
    v.SetterCapacity(Capacity);
    v.SetterDriverName(DriverName);
    // ADDING OBJECT v TO VECTOR VANS WE CREATED IN MANAGER.H
    Vans.push_back(v);
    cout << "\nVan is added successfully!!!\n";
}
// FINAL REPORT
// LOGIC FOR SHOWING FINAL SYSTEM REPORT THAT WILL DISPLAY ALL THE DATA ENTERED BY MANAGER — STUDENTS, DRIVERS, VANS, COMPLAINTS (IF ANY)
void Manager::ViewFullReport() {
    // HEADLINE FOR REPORT
    cout << "\n========== FINAL SYSTEM REPORT =========="<<endl;
    // FIRST DISPLAYING STUDENT DATA
    cout << "\n----- STUDENT RECORDS -----"<<endl;
    // CHECKING IF THE STUDENTS VECTOR IS EMPTY OR NOT
    if (Students.empty()) {
        cout << "No students added yet."<<endl;
    } else {
        // LOOP THROUGH EACH STUDENT OBJECT IN THE VECTOR
        for (int i = 0; i < Students.size(); i++) {
            cout << "Student " << i + 1 <<endl;
            // DISPLAYING BASIC INFO — FROM BASEUSER CLASS
            cout << "Name: " << Students[i].GetterName() << endl;
            cout << "ID: " << Students[i].GetterIdNo() << endl;
            cout << "Gender: " << Students[i].GetterGender() << endl;
            cout << "Contact: " << Students[i].GetterContactNum() << endl;
            cout << "Role: " << Students[i].GetterRole() << endl;

            // DISPLAYING STUDENT-SPECIFIC INFO
            cout << "Pickup Location: " << Students[i].GetterSPL() << endl;
            cout << "Drop Location: " << Students[i].GetterSDL() << endl;
            cout << "Assigned Van No: " << Students[i].GetterAVN() << endl;
        }
    }
    // SECONDLY DISPLAYING DRIVER DATA
    cout << "----- DRIVER RECORDS -----"<<endl;
    // CHECK IF DRIVER VECTOR IS EMPTY OR NOT
    if (Drivers.empty()) {
        cout << "No drivers added yet.\n";
    } else {
        // LOOP THROUGH EACH DRIVER OBJECT AND DISPLAY THEIR INFO
        for (int i = 0; i < Drivers.size(); i++) {
            cout << "Driver " << i + 1 <<endl;
            // BASEUSER INFO
            cout << "Name: " << Drivers[i].GetterName() << endl;
            cout << "ID: " << Drivers[i].GetterIdNo() << endl;
            cout << "Gender: " << Drivers[i].GetterGender() << endl;
            cout << "Contact: " << Drivers[i].GetterContactNum() << endl;
            cout << "Role: " << Drivers[i].GetterRole() << endl;

            // DRIVER-SPECIFIC INFO
            cout << "License No: " << Drivers[i].GetterLicenseNo() << endl;
            cout << "Assigned Van No: " << Drivers[i].GetterAssignedVanNo() << endl;
        }
    }

    // THIRDLY DISPLAYING VAN DATA
    cout << "\n----- VAN RECORDS -----\n";
    // CHECKING IF VANS EXIST
    if (Vans.empty()) {
        cout << "No vans added yet.\n";
    } else {
        // LOOP THROUGH EACH VAN OBJECT AND PRINT ITS INFO
        for (int i = 0; i < Vans.size(); i++) {
            cout << "\nVan " << i + 1 << ":\n";
            cout << "Van No: " << Vans[i].GetterVanNo() << endl;
            cout << "Driver Name: " << Vans[i].GetterDriverName() << endl; // IMPORTANT TO TIE DRIVER TO VAN
            cout << "Route: " << Vans[i].GetterRoute() << endl;
            cout << "Capacity: " << Vans[i].GetterCapacity() << endl;
        }
    }

    /* FOURTHLY DOING COMPAINT DATA
    cout << "----- COMPLAINT RECORDS -----"<<endl;
    // COMPLAINTS MAY BE HANDLED LATER BUT WE KEEP SPACE FOR IT
    if (Complaints.empty()) {
        cout << "No complaints added yet.\n";
    } else {
        for (int i = 0; i < Complaints.size(); i++) {
            cout << "\nComplaint " << i + 1 << ":\n";
            cout << Complaints[i] << endl;
        }
    }*/
    // END MESSAGE FOR REPORT
    cout << "========== END OF REPORT =========="<<endl;
}

