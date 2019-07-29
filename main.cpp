#include <iostream>
#include <string>
#include "util/QueryManager.h"
#include "util/FileManager.h"
#include "util/Functions.h"

using namespace std;

int main() {
    FileManager::createDataDirIfAbsent();

    fstream sysCat;
    FileManager::openOrCreateInitializeOpenSysCat(sysCat);

    Functions::printWelcome();
    string line;
    do {
        Functions::printPrompt();
        getline(cin, line);
        try {
            QueryManager::parseAndExecute(sysCat, line);
        } catch (string &message) {
            cout << message << endl;
        }
    } while(line != "q");

    Functions::printGoodBye();

    sysCat.close();
}
