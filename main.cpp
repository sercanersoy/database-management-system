#include <iostream>
#include "util/QueryManager.h"
#include "util/FileManager.h"
#include "util/Functions.h"

using namespace std;

void openCommandLineMode() {
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
    } while (line != "q");

    Functions::printGoodBye();

    sysCat.close();
}

void openInputOutputMode(string &inputPath, string &outputPath) {
    FileManager::createDataDirIfAbsent();

    ifstream input;
    input.open(inputPath);
    if (!input) {
        cerr << "Error opening input file." << endl;
        exit(1);
    }

    ofstream output;
    output.open(outputPath);
    if (!output) {
        cerr << "Error opening output file." << endl;
        exit(1);
    }
    QueryManager::output = &output;

    fstream sysCat;
    FileManager::openOrCreateInitializeOpenSysCat(sysCat);

    string line;
    while (getline(input, line)) {
        try {
            QueryManager::parseAndExecute(sysCat, line);
        } catch (string &message) {
            cout << message << endl;
        }
    }

    sysCat.close();
    input.close();
    output.close();
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        openCommandLineMode();
    } else if (argc == 3) {
        string inputPath = argv[1];
        string outputPath = argv[2];
        openInputOutputMode(inputPath, outputPath);
    } else {
        cerr << "Invalid number of arguments." << endl;
        exit(1);
    }
}
