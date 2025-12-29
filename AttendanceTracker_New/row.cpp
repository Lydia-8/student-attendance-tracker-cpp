#include <iostream>
#include "row.h"
using namespace std;

// Insert attendance row
void insertRow(int studentID[], string name[], string status[], int &rowCount)
{
    if (rowCount >= MAX_ROWS)
    {
        cout << "Error: Row limit reached." << endl;
        return;
    }

    cout << "Enter StudentID: ";
    cin >> studentID[rowCount];

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name[rowCount]);

    cout << "Enter Status (1 = Present, 0 = Absent): ";
    cin >> status[rowCount];

    rowCount++;

    cout << "Row inserted successfully.\n\n";
}

// Display CSV format
void displayCSV(int studentID[], string name[], string status[], int rowCount)
{
    cout << "StudentID, Name, Status\n";

    for (int i = 0; i < rowCount; i++)
    {
        cout << studentID[i] << ", "
             << name[i] << ", "
             << status[i] << endl;
    }
}

