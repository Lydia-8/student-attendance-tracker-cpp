#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// column and sheet class
struct column
{
    string name;
    int type;
};

class sheet
{
    string sheetName;
    vector<column> columns;

public:
    void createSheet(const string &name)
    {
        sheetName = name;
        columns.clear();
        cout << "Attendance sheet \"" << sheetName << "\" created successfully!\n\n";
    }
    void addColummn(const string &name, int type)
    {
        columns.push_back({name, type});
    }
};

// validation functions
int getInt(string prompt, int min, int max)
{
    int value;
    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < min || value > max)
        {
            cin.clear();            // clear error
            cin.ignore(1000, '\n'); // discard input
            cout << "Invalid input. Try again.\n";
        }
        else
        {
            cin.ignore(1000, '\n'); // remove leftover newline
            return value;
        }
    }
}
string getString(string prompt)
{
    string input;
    while (true)
    {
        cout << prompt;
        getline(cin, input);

        if (!input.empty())
        {
            return input;
        }
        cout << "Input cannot be empty. Try again.\n";
    }
}

// row functions
const int MAX_ROWS = 100;

void insertRow(int studentID[], string name[], string status[], int &rowCount)
{
    if (rowCount >= MAX_ROWS)
    {
        cout << "Cannot add more rows. Maximum limit reached.\n";
        return;
    }

    cout << "Enter Student ID: ";
    cin >> studentID[rowCount];
    cin.ignore(); // clear newline

    cout << "Enter Name: ";
    getline(cin, name[rowCount]);

    cout << "Enter Status (Present/Absent): ";
    getline(cin, status[rowCount]);

    rowCount++;
    cout << "Row added successfully!\n\n";
}

void displayCSV(int studentID[], string name[], string status[], int rowCount)
{
    cout << left << setw(15) << "Student ID" << setw(25) << "Name" << setw(15) << "Status" << endl;
    cout << string(55, '-') << endl;

    for (int i = 0; i < rowCount; i++)
    {
        cout << left << setw(15) << studentID[i] << setw(25) << name[i] << setw(15) << status[i] << endl;
    }
}

// main program
int main()
{
    cout << "Student Attendance Tracker" << endl;
    cout << "***************************" << endl;

    string sheetName = getString("Enter attendance sheet name: ");
    sheet mySheet;
    mySheet.createSheet(sheetName);

    int n = getInt("Enter number of columns, max 10: ", 1, 10);

    for (int i = 0; i < n; i++)
    {
        string colName = getString("\nEnter column name(" + to_string(i + 1) + "): ");
        int colType = getInt("Select data type (1 for INT and 2 for TEXT):", 1, 2);

        mySheet.addColummn(colName, colType);
    }

    cout << "\nSheet structure succesfully created\n";

    // Manageing rows
    int studentID[MAX_ROWS];
    string name[MAX_ROWS], status[MAX_ROWS];
    int rowCount = 0;

    char choice;
    do
    {
        insertRow(studentID, name, status, rowCount);

        cout << "Do you want to add another row? (y/n): ";
        cin >> choice;
        cin.ignore(); // clear newline
    } while (choice == 'y' || choice == 'Y');

    // Display final sheet
    cout << "\nFinal Attendance Sheet: " << sheetName << "\n";
    displayCSV(studentID, name, status, rowCount);

    return 0;
}