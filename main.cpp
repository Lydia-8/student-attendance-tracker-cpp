#include <iostream>
#include <iomanip>
#include <vector>

#include "row.h" // include row functions

using namespace std;

struct column {
    string name;
    int type;
};

class sheet {
    string sheetName;
    vector<column> columns;
    public:
    void createSheet(const string& name){
        sheetName = name;
        columns.clear();
       cout << "Attendance sheet \"" << sheetName << "\" created successfully!\n\n";
    }
    void addColummn(const string& name, int type){
        columns.push_back({name,type});
    }

};

int main()
{
    cout << "Student Attendance Tracker" << endl;
    cout << "***************************" << endl;

    //ask for sheet name (create sheet)
    string sheetName;
    cout<< "Enter attendance sheet name: ";
    getline(cin, sheetName);

    sheet mySheet;
    mySheet.createSheet(sheetName);

    // ask for number of columns (add columns)
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

    // Loop to add each column
    for (int i = 0; i < n; i++){
        string colName;
        int colType;

        cout<< "\nEnter column name("<< i + 1 << "): ";
        cin.ignore();
        getline(cin,colName);

        //ask for column type
        while (true){
            cout << "Select data type (1 for INT and 2 for TEXT): ";
            cin >> colType;

            if(colType == 1 || colType == 2){
                mySheet.addColummn(colName, colType);
                break;
            }else{
                cout<< "Invalid input. Please re-enter\n";
            }
        }
    }

    // Print confirmation message
    cout << "\nSheet structure succesfully created";

    // Managing rows
    int studentID[MAX_ROWS];
    string name[MAX_ROWS], status[MAX_ROWS];
    int rowCount=0;

    char choice;
    do
    {
        insertRow(studentID,name, status, rowCount);
        cout << "Add aother row? (y/n):\n";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y' || choice == 'Y');

    // Display final sheet
    cout << "\nFinal Attendance Sheet:\n";
    displayCSV(studentID, name, status, rowCount);


    return 0;
}
