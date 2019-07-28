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

using namespace std;

void assignCharArray(char * array, const char * toAssign, int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = toAssign[i];
    }
}

void printWelcome() {
    cout << "Welcome!" << endl;
    cout << "Enter 'h' for help, 'q' to exit." << endl;
    cout << "Enter your command: " << endl;
    // TODO proper welcome message
}

int main() {
    FileManager::createDataDirIfAbsent();

    fstream sysCat;
    FileManager::createInitializeSysCatAndOpen(sysCat);

    printWelcome();
    string line;
    do {
        cout << "> ";
        getline(cin, line);
        try {
            QueryManager::parseAndExecute(line);
        } catch (string &message) {
            cout << message << endl;
        }
    } while(line != "q" && line != "Q");

    cout << "See you later!" << endl;

    sysCat.close();
}
