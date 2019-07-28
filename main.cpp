#include <iostream>
#include <string>
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>
#include <algorithm>
#include "config.h"
#include "model/dataFile/DataFilePage.h"
#include "model/sysCat/SysCatPage.h"
#include "util/QueryManager.h"
#include "util/FileManager.h"
#include "util/Functions.h"

using namespace std;

int main() {
    FileManager::createDataDirIfAbsent();

    fstream sysCat;
    FileManager::createInitializeSysCatAndOpen(sysCat);

    Functions::printWelcome();
    string line;
    do {
        cout << "> ";
        getline(cin, line);
        if(line == "q") {
            break;
        }
        try {
            QueryManager::parseAndExecute(sysCat, line);
        } catch (string &message) {
            cout << message << endl;
        }
    } while(true);

    cout << "See you later!" << endl;

    sysCat.close();
}
