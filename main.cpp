#include <iostream>
#include <string>
#include "constants.h"
#include "model/dataFile/DataFilePage.h"
#include "model/sysCat/SysCatPage.h"

using namespace std;

int main() {
    SysCatPage sysCatPage;
    cout << "Size of a system catalog page is: " << sizeof(sysCatPage) << endl;

    DataFilePage dataFilePage;
    cout << "Size of a data file page is: " << sizeof(dataFilePage) << endl;
}
