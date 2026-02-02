// *********************************************************
// Program: TC1L_GROUP10_MILESTONE2.cpp
// Course: CCP6114 Programming Fundamentals
// Lecture Class: TC1L
// Tutorial Class: TT2L and TT4L
// Trimester: 2530
// Member_1: ID | AISYAH BINTI AHMAD NIZAM | AISYAH.AHAMAD.NIZAM1@student.mmu.edu.my | 011-11212-126
// Member_2: ID | NUR NAJWA NABILAH BINTI MOHD AZRIN | EMAIL | 016-6867-890
// Member_3: ID | HANUSA A/P SUBRAMANIAM | HANUSA.SUBRAMANIAM1@student.mmu.edu.my | 018-6217-622
// Member_4: ID | LYDIA BINTI MOHD JEFFRY LEE | EMAIL | 018-2705-857
// *********************************************************
// Task Distribution
// Member_1:
// Member_2:
// Member_3:
// Member_4:
//


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <fstream>

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

    string getSheetName()
    {
         return sheetName;
    }
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
            return input;

        cout << "Input cannot be empty. Try again.\n";
    }
}

// main program
int main()
{
    // Milestone 1
    cout << "***************" << endl;
    cout << "STUDENT ATTENDANCE TRACKER - MILESTONE 1\n";
    cout << "***************" << endl;

    string sheetName;
    cout << "Enter attendance sheet name: ";
    getline(cin, sheetName);

    sheet mySheet;
    mySheet.createSheet(sheetName);

    int n;
    while (true)
    {
        cout << "Enter number of columns, max 10: ";
        cin >> n;
        if (n > 0 && n <= 10)
        {
            break;
        }
        else
        {
            cout << "Please enter number <=10. \n";
        }
    }

    // Loop
    for (int i = 0; i < n; i++)
    {
        string colName;
        int colType;

        cout << "\nEnter column name(" << i + 1 << "): ";
        cin.ignore();
        getline(cin, colName);

        while (true)
        {
            cout << "Select data type (1 for INT and 2 for TEXT): ";
            cin >> colType;

            if (colType == 1 || colType == 2)
            {
                mySheet.addColumn(colName, colType);
                break;
            }
            else
            {
                cout << "Invalid input. Please re-enter\n";
            }
        }
    }

    cout << "\nSheet structure succesfully created\n";

    // row function

    char choice;
    vector<vector<string>> database;

    do
    {
        cout << "\n-------------------------------------------\n";
        cout << "Insert New Attendance Row\n";
        cout << "-------------------------------------------\n";

        vector<string> newRow;
        int j = 0;
        vector<column> &cols = mySheet.getColumns();
        int numCols = cols.size();

        cin.ignore();

        while (j < numCols)
        { // if j < n
            string userData;
            cout << "Enter " << cols[j].name << ": ";
            getline(cin, userData);

            // chcek int or txt
            if (cols[j].type == 1)
            {
                bool isNumber = true;
                if (userData.empty())
                    isNumber = false;

                for (char const &c : userData)
                {
                    if (!isdigit(c))
                    {
                        isNumber = false;
                        break;
                    }
                }

                if (!isNumber)
                { // is user data a number? - no
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

    // display final sheet

    cout << "\n-------------------------------------------\n";
    cout << "View Attendance Sheet (CSV Mode)\n";
    cout << "-------------------------------------------\n";

    vector<column> &finalCols = mySheet.getColumns();
    for (int i = 0; i < finalCols.size(); i++)
    {
        cout << left << setw(20) << finalCols[i].name;
    }
    cout << endl;

    cout << string(finalCols.size() * 20, '-') << endl;

    for (const auto &row : database)
    {
        for (int k = 0; k < row.size(); k++)
        {
            cout << left << setw(20) << row[k];
        }
        cout << endl;
    }

    cout << "\n------------------------------------------------------\n";
    cout << "End of Sheet.\n";


    // MILESTONE 2

    cout << "\n===========================================\n";
    cout << "   STUDENT ATTENDANCE TRACKER - MILESTONE 2\n";
    cout << "===========================================\n";

    string term_name;
    cout << "Enter term name: ";
    cin.ignore();
    getline(cin, term_name);

    cout << "Database \"" << term_name << "\" created and loaded.\n";

    string saveFileName;

        while (true)
    {
        cout << "\nEnter attendance file to load: ";
        getline(cin, saveFileName);

        // sheetname from Milestone 1
        if (saveFileName == sheetName)
        {
            break;
        }
        else
        {
            cout << "Error: Attendance file does not exist, Please check again\n";
        }
    }

        cout << "\nReading attendance data from file...\n";
        cout << "Successfully loaded: " << saveFileName << "_Attendance.csv\n\n";

        cout << "-------------------------------------------\n";
        cout << "Current Attendance Sheet\n";
        cout << "-------------------------------------------\n";

   vector<column>& finalCols2 = mySheet.getColumns();

    // Print Header
    for (int i = 0; i < finalCols2.size(); i++) {
        cout << finalCols2[i].name;
        if (i < finalCols2.size() - 1) cout << ", ";
    }
    cout << endl;

    // Print Rows
    for (const auto& row : database) {
        for (int i = 0; i < row.size(); i++){
            cout << row[i];
            if (i < row.size() - 1) cout << ", ";
        }
        cout << endl;
    }

    //Update row part

    cout << "\n-------------------------------------------\n";
    cout << "UPDATE ATTENDANCE ROW\n";
    cout << "-------------------------------------------\n";

    char updateChoice;
    cout << "Do you want to update a row? (y/n): ";
    cin >> updateChoice;

    if (updateChoice == 'y' || updateChoice == 'Y')
    {
        string searchID;
        bool found = false;

        int idColIndex = 0;
        int statusColIndex = finalCols2.size() - 1;

        while (true)
        {
            found = false;

            while(true) {
                cout << "\nEnter StudentID to update (INT only): ";
                cin >> searchID;

                bool isNum = true;
                for(char c : searchID) {
                    if(!isdigit(c)) { isNum = false; break; }
                }

                if(!isNum) {
                    cout << "Error: invalid integer. Try again\n";
                } else {
                    break;
                }
            }

            for (auto& row : database) {
                if (row[idColIndex] == searchID) {
                    found = true;

                    string newStatus;

                    // Status Validation
                    while(true) {
                        cout << "Enter new status: ";
                        cin >> newStatus;

                        if(newStatus == "1" || newStatus == "0") {
                            break;
                        } else {
                             cout << "Invalid status. Please enter 1 or 0\n";
                        }
                    }

                    //Update Memory
                    row[statusColIndex] = newStatus;

                    //Update File
                    ofstream updateFile(saveFileName + "_Attendance.csv");
                    if (updateFile.is_open()) {
                        for (int i = 0; i < finalCols2.size(); i++) {
                            updateFile << finalCols2[i].name << (i == finalCols2.size() - 1 ? "" : ",");
                        }
                        updateFile << "\n";
                        for (const auto& r : database) {
                            for (int k = 0; k < r.size(); k++) {
                                updateFile << r[k] << (k == r.size() - 1 ? "" : ",");
                            }
                            updateFile << "\n";
                        }
                        updateFile.close();
                    }

                    cout << "Row updated successfully.\n";
                    break;
                }
            }

            //Display updated sheet

            if (found) {
                cout << "\nUpdated Sheet:\n";

                //Print Header
                for (int i = 0; i < finalCols2.size(); i++) {
                    cout << finalCols2[i].name;
                    if (i < finalCols2.size() - 1) cout << ", ";
                }
                cout << endl;

                //Print Rows
                for (const auto& row : database) {
                    for (int i = 0; i < row.size(); i++){
                        cout << row[i];
                        if (i < row.size() - 1) cout << ", ";
                    }
                    cout << endl;
                }

                break;
            }
            else {

                cout << "Error: StudentID does not exist. Please try again.\n";
            }

        }

    }

    // Delete row part

    cout << "\n-------------------------------------------\n";
    cout << "DELETE ATTENDANCE ROW\n";
    cout << "-------------------------------------------\n";

    char deleteChoice;
    cout << "Do you want to delete any row? (y/n): ";
    cin >> deleteChoice;

    if (deleteChoice == 'y' || deleteChoice == 'Y')
    {
        string deleteID;
        bool found = false;
        int idColIndex = 0;

        while (true)
        {
            found = false;

            while(true) {
                cout << "\nEnter StudentID to delete (INT only): ";
                cin >> deleteID;

                bool isNum = true;
                for(char c : deleteID) {
                    if(!isdigit(c)) { isNum = false; break; }
                }

                if(!isNum) {
                    cout << "Error: invalid integer. Try again\n";
                } else {
                    break;
                }
            }

            for (int i = 0; i < database.size(); i++)
            {
                if (database[i][idColIndex] == deleteID)
                {
                    database.erase(database.begin() + i);
                    found = true;

                    ofstream deleteFile(saveFileName + "_Attendance.csv");
                    if (deleteFile.is_open()) {
                        for (int j = 0; j < finalCols2.size(); j++) {
                            deleteFile << finalCols2[j].name << (j == finalCols2.size() - 1 ? "" : ",");
                        }
                        deleteFile << "\n";
                        for (const auto& r : database) {
                            for (int k = 0; k < r.size(); k++) {
                                deleteFile << r[k] << (k == r.size() - 1 ? "" : ",");
                            }
                            deleteFile << "\n";
                        }
                        deleteFile.close();
                    }

                    cout << "Row deleted successfully.\n";
                    break;
                }
            }

            if (found) {
                cout << "\nUpdated Sheet:\n";
                for (int i = 0; i < finalCols2.size(); i++) {
                    cout << finalCols2[i].name;
                    if (i < finalCols2.size() - 1) cout << ", ";
                }
                cout << endl;
                for (const auto& row : database) {
                    for (int i = 0; i < row.size(); i++) {
                        cout << row[i];
                        if (i < row.size() - 1) cout << ", ";
                    }
                    cout << endl;
                }
                break;
            }
            else {
                cout << "Error: StudentID does not exist. Please try again.\n";
            }
        }
    }

    // Count rows

    char countChoice;
    cout << "\nDo you want to count the total attendance rows? (y/n): ";
    cin >> countChoice;

    if (countChoice == 'y' || countChoice == 'Y') {
        cout << "-------------------------------------------" << endl;
        cout << "Count Rows" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Number of rows: " << database.size() << endl; // Uses the current size of the vector
    }

    // Writing updated sheet
    cout << "\n-------------------------------------------\n";
    cout << "Writing updated sheet to output file...\n";

    ofstream outFile(saveFileName + "_Updated.csv");
    if (outFile.is_open()) {


        for (size_t i = 0; i < finalCols2.size(); i++) {
            outFile << finalCols2[i].name << (i == finalCols2.size() - 1 ? "" : ",");
        }
        outFile << "\n";


        for (const auto& row : database) {
            for (size_t k = 0; k < row.size(); k++) {
                outFile << row[k] << (k == row.size() - 1 ? "" : ",");
            }
            outFile << "\n";
        }
        outFile.close();
        cout << "Output saved as: " << saveFileName << "_Updated.csv" << endl;
    } else {
        cout << "Error: Could not save the updated file." << endl;
    }

    cout << "-------------------------------------------\n";
    cout << "End of Milestone 2 Output\n";
    cout << "Program End." << endl;

    return 0;
}
