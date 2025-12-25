#include <iostream>
#include <string>
#include <vector>

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
int main(){

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
        cout << "Please enter number <=10. ";
    }
}

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
            mySheet.addColummn(colName, colType);
            break;
        }else{
            cout<< "Invalid input. Please re-enter\n";
        }
    }
}

cout << "\nSheet structure succesfully created";

return 0;
}