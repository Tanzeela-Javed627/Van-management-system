// INCLUDING EVERY HEADERFILE
#include <iostream>
#include "Manager.h"
#include "Student.h"
#include "Driver.h"
#include "VanInfo.h"
#include "Complain.h"
#include "BaseUser.h"
#include "TimeSlot.h"
using namespace std;
int main() {
   // MAKING OBJECTS OF EVERY CLASS
    Manager manager;
    Student student;
    Driver driver;
    int MainChoice;
    do {
        // MAIN MENU FOR USERS
        cout << "==== VAN MANAGEMENT SYSTEM ===="<<endl;
        cout << "1. Student\n";
        cout << "2. Driver\n";
        cout << "3. Manager\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> MainChoice;
        // CHOICES LOGIC
        switch (MainChoice) {
            case 1: {
                int StuChoice;
                cout << "\n\t\a--- STUDENT PANEL ---"<<endl;
                cout << "1. View Assigned Van Details\n";
                cout << "2. Write Complaint\n";
                cout << "Enter your choice: ";
                cin >> StuChoice;
                if (StuChoice == 1) {
                    manager.ShowAssignedVanToStudent(); // SHOW VAN INFO FOR STUDENT
                }
                else if (StuChoice == 2) {
                    student.WriteComplain();
                }
                else {
                    cout << "Invalid Student option selected.\n";
                }
                break;
            }

            case 2: {
                int DriChoice;
                cout << "\n\t\t\a--- DRIVER PANEL ---\n";
                cout << "1. View Assigned Van Details\n";
                cout << "2. Enter trip status: \n";
                cout << "Enter your choice: ";
                cin >> DriChoice;

                if (DriChoice == 1) {
                    manager.ShowAssignedVanToDriver(); // SHOW VAN INFO FOR DRIVER
                }
                else if (DriChoice == 2) {
                    string s;
                    cout<<"Enter the trip status (Started/Completed)"<< endl;
                    cin>>s;
					driver.SetterTripStatus(s);
//cout << "DEBUG: Trip status set to: " << driver.GetterTripStatus() << endl; // ENTER TRIP STATUS
					cout<<"Your trip status will be shown to the manager"<<endl;
                }
                else {
                    cout << "Invalid Driver option selected.\n";
                }
                break;
            }

            case 3: {
                int ManChoice;
                cout << "\n\t\t\a--- MANAGER PANEL ---\n";
                cout << "1. Add Student\n";
                cout << "2. Delete Student\n";
                cout << "3. Add Driver\n";
                cout << "4. Delete Driver\n";
                cout << "5. Add Van\n";
                cout << "6. View All Complaints\n";
                cout << "7. Assign Student\n";
                cout << "8. Assign Drivers\n";
                cout << "9. View Full Report\n";
                cout << "10. View Trip Status\n";
                cout << "Enter your choice: ";
                cin >> ManChoice;

                switch (ManChoice) {
                    case 1:
                        manager.AddStu();
                        break;
                    case 2:
                        manager.DelStu();
                        break;
                    case 3:
                        manager.AddDri();
                        break;
                    case 4:
                        manager.DelDri();
                        break;
                    case 5:
                        manager.AddVan();
                        break;
                    case 6:
                        manager.ViewComplain();
                        break;
                    case 7:
                        manager.AssignStu();
                        break;
                    case 8:
                        manager.AssignDri();
                        break;
                    case 9:
                        manager.ViewFullReport();
                        break;
                    case 10:
                    	cout<<"This is the trip status entered by the driver: "<<driver.GetterTripStatus();
                        cout<<endl;
                        break;
                    default:
                        cout << "Invalid Manager option selected.\n";
                }
                break;
            }

            case 4:
                cout << "\aExiting the system... Thank you!\n";
                break;

            default:
                cout << "Invalid option. Please select from 1 to 4.\n";
        }

    } while (MainChoice != 4);

    return 0;
}
