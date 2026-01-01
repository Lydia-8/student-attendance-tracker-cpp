#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

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
    vector<vector<string>> dataRows;

public:
    void createSheet(const string &name)
    {
        sheetName = name;
        columns.clear();
        dataRows.clear();
        cout << "Attendance sheet \"" << sheetName << "\" created successfully!\n\n";
    }

    void addColumn(const string &name, int type)
    {
        columns.push_back({name, type});
    }

    vector<column>& getColumns()
    {
        return columns;
    }

    string getSheetName() { return sheetName; }
};

// validation function

int getInt(string prompt, int min, int max)
{
    int value;
    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < min || value > max)
        {
            cin.clear();               //clear error
            cin.ignore(1000, '\n');   //discard input
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
            return input;

        cout << "Input cannot be empty. Try again.\n";
    }
}


// main program
int main()
{
    cout << "***************" << endl;
    cout << "STUDENT ATTENDANCE TRACKER - MILESTONE 1\n";
    cout << "***************" << endl;

    string sheetName;
    cout<< "Enter attendance sheet name: ";
    getline(cin, sheetName);

    sheet mySheet;
    mySheet.createSheet(sheetName);

int n;
    while(true){
        cout<< "Enter number of columns, max 10: ";
        cin >> n;
        if (n>0 && n<=10){
            break;
        }else{
            cout << "Please enter number <=10. \n";
        }
    }

    // Loop
    for (int i = 0; i < n; i++){
        string colName;
        int colType;

        cout<< "\nEnter column name("<< i + 1 << "): ";
        cin.ignore();
        getline(cin,colName);

        while (true){
            cout << "Select data type (1 for INT and 2 for TEXT): ";
            cin >> colType;

            if(colType == 1 || colType == 2){
                mySheet.addColumn(colName, colType);
                break;
            }else{
                cout<< "Invalid input. Please re-enter\n";
            }
        }
    }

    cout << "\nSheet structure succesfully created\n";

    //row function

    char choice;
    vector<vector<string>> database;

    do {
        cout << "\n-------------------------------------------\n";
        cout << "Insert New Attendance Row\n";
        cout << "-------------------------------------------\n";

        vector<string> newRow;
        int j = 0;
        vector<column>& cols = mySheet.getColumns();
        int numCols = cols.size();

        cin.ignore();

        while (j < numCols) { // if j < n
            string userData;
            cout << "Enter " << cols[j].name << ": ";
            getline(cin, userData);

            // chcek int or txt
            if (cols[j].type == 1) {
                bool isNumber = true;
                if (userData.empty()) isNumber = false;

                for (char const &c : userData) {
                    if (!isdigit(c)) {
                        isNumber = false;
                        break;
                    }
                }

                if (!isNumber) { // is user data a number? - no
                    cout << "Error: Invalid INT value. Please enter a number.\n";
                    continue;
                }
            }

            newRow.push_back(userData);
            j = j + 1;
        }

        database.push_back(newRow);
        cout << "\nRow inserted succesfully\n";

        cout << "Do you want to insert new attendance row? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nAll data saved. Exiting program.\n";

    //display final sheet

    cout << "\n-------------------------------------------\n";
    cout << "View Attendance Sheet (CSV Mode)\n";
    cout << "-------------------------------------------\n";

    vector<column>& finalCols = mySheet.getColumns();
    for (int i = 0; i < finalCols.size(); i++) {
        cout << left << setw(20) << finalCols[i].name;
    }
    cout << endl;

    cout << string(finalCols.size()*20, '-') << endl;

    for (const auto& row : database) {
        for (int k = 0; k < row.size(); k++){
            cout << left << setw(20) << row[k];
        }
        cout << endl;
    }

    cout << "\n------------------------------------------------------\n";
    cout << "End of Sheet.\n";

    return 0;
}
