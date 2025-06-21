#pragma once
#include"Student.h"
#include"Driver.h"
#include"VanInfo.h"
#include"Complain.h"
#include"BaseUser.h"
#include"TimeSlot.h"
#include<vector>
// ADDED HEADERFILES IN MANAGER.H TO ACCESS THE VECTORS OF DIFFERENT ENTITIES
using namespace std;
class Manager : public BaseUser{
	private:
		vector<Student> Students;// OOP COMPOSITION
		vector<Driver> Drivers;
		vector<VanInfo> Vans;
	public:
	//DEFAULT CONSTRUCTOR
	Manager();
	// PARACONSTRUCTOR
	Manager(string n,int i,char g,string c, string r);
	// DECLARING DIFFERENT FUNCTIONS THAT DEFINES THE MANAGER WORKINGS
	void AddStu();
	void DelStu();
	void ShowAssignedVanToStudent();
	void ShowAssignedVanToDriver();
	void AddDri();
	void DelDri();
	void AddVan(); // TO ADD VAN INFO
	void ViewComplain();
	void AssignStu();//TO VAN
	void AssignDri();//TO VAN
	void ViewFullReport();//THIS LIST HAS STUDENT NAMES STUDENT
};
