#include "complain.h"
// LOGIC FOR WRITING THE COMPLAIN
void Complain::WriteComplaint() {
    ofstream OutFile("Complaints.txt", ios::app); // FOR APPENDING
    if (!OutFile) {// IF FILE DOESNT EXISTS
        cout << "Error opening file for writing." << endl;
        return;
    }
    cout << "Enter your complaint (YOUR COMPLAINS WILL BE COMPLETELY ANONYMOUS AND WILL NEVER BE ADDRESSED ): ";
    cin.ignore();
    getline(cin, ComplaintText);
    OutFile << ComplaintText << endl;
    OutFile.close();
    cout << "THANKS FOR COMPLAINING :).\n";
}
// LOGIC FOR READING COMPLAINS
void Complain::ReadComplaints() {
    ifstream InFile("complaints.txt");
    if (!InFile) {
        cout << "No complaints found or file couldn't be opened.\a\n";
        return;
    }
    cout << "\n\t\a--- All Anonymous Complaints ---\n";
    string line;
    int count = 1;
    while (getline(InFile, line)) {// READ ONE LINE FROM THE FILE INTO THE LINE STRING UNTIL IT HITS
        cout << count << ". " << line << endl;
        count++;
    }
    InFile.close();
}
