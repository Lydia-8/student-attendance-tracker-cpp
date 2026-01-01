#include <iostream>
#include <iomanip>

using namespace std;

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