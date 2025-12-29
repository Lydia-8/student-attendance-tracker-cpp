#ifndef ROW_H
#define ROW_H

#include <string>
using namespace std;

const int MAX_ROWS = 100;

void insertRow(int studentID[], string name[], string status[], int &rowCount);
void displayCSV(int studentID[], string name[], string status[], int rowCount);

#endif
