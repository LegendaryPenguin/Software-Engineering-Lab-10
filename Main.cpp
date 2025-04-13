#include "Matrix.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: ./program <input_file>" << endl;
        return 1;
    }
    string filename = argv[1];
    ifstream infile(filename.c_str());
    if (!infile) {
        cout << "Cannot open file: " << filename << endl;
        return 1;
    }
    string line;
    string addend = "-123.456";
    string multiplier = "2.0";
    while (getline(infile, line)) {
        while (!line.empty() && std::isspace(line[0]))
            line.erase(line.begin());
        while (!line.empty() && std::isspace(line[line.size()-1]))
            line.erase(line.end()-1);
        if (line == "")
            continue;
        if (isValidDouble(line)) {
            string added = addDoubleStrings(line, addend);
            string multiplied = multiplyDoubleStrings(line, multiplier);
            cout << "Valid number: " << line << endl;
            cout << "After adding " << addend << ", result: " << added << endl;
            cout << "After multiplying by " << multiplier << ", result: " << multiplied << endl;
        } else {
            cout << "Invalid number: " << line << endl;
        }
    }
    infile.close();
    return 0;
}
