#pragma once
#include <iostream>
#include <fstream>// FILE HANDLING
#include <string>
using namespace std;
class Complain {
private:
    string ComplaintText;
public:
    Complaint();  // Default constructor
    void WriteComplaint();   // For taking input AND writing to file
    void ReadComplaints();   // For reading all complaints from file
};
