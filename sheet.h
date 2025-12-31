#ifndef SHEET_H
#define SHEET_H

#include <string>
#include <vector>

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
    void createSheet(const string &name);
    void addColumn(const string &name, int type);
};

#endif
