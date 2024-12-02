#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring> // strtok
#include <algorithm>
using namespace std;

/*

infinite loop
    currentCyle++
    if noop -> currentInstruction++
    if addx -> addxWorking = true -> in middle of cycle change
    if addxWorking -> xRegister += value; currentInstruction++

    check if interesing cycle -> sumOfSignalStrength += strength
*/


vector<string> splitStr(string str, const char* sep) {
    vector<string>returnedStr = {};
	char *token = strtok(str.data(), sep);

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        // cout << "1--" << token << endl;
        returnedStr.push_back(token);
        token = strtok(NULL, sep);
    }

    return returnedStr;
}

bool isInterestingCycle(int currentCycle) {
    int interestingCycles[] = { 20, 60, 100, 140, 180, 220 };

    return find(begin(interestingCycles), end(interestingCycles), currentCycle) != end(interestingCycles);

}

int main() {
    vector<string> instructions = {};

    int currentCycle = 0;
    int currentInstruction = 0;

    int xRegister = 1;
    int sumOfSignalStrengths = 0;

    int addxValue = 0;
    bool addxWorking = false;
    
    int interestingCycles[] = { 20, 60, 100, 140, 180, 220 };

    // fill the instructions vector
    string line;
    ifstream myfile ("inp.in");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            instructions.push_back(line);
        }
        myfile.close();
    }
    else { cout << "file not found" << endl; }


    while (currentInstruction < instructions.size()) {
        currentCycle++;

        vector<string> instr = splitStr(instructions[currentInstruction], " "); // instruction, number

        // if (addxWorking) {
        //     addxWorking = false;
        //     xRegister += addxValue;
        //     currentInstruction++;
        //     // cout << addxValue << " " << currentCycle << endl;
        // }

        if (instr[0] == "noop") {
            currentInstruction++;
        }
        else if (instr[0] == "addx") {
            addxWorking = true;
            addxValue = stoi(instr[1]);
        }

        // current cycle is interesting cycle
        if (find(begin(interestingCycles), end(interestingCycles), currentCycle) != end(interestingCycles)) {
            // calculate signal strengths
            sumOfSignalStrengths += xRegister * currentCycle;
            cout << endl << xRegister << "  " << currentCycle << endl;
        }

        if (addxWorking && !(instr[0] == "addx")) {
            addxWorking = false;
            xRegister += addxValue;
            currentInstruction++;
            // cout << addxValue << " " << currentCycle << endl;
        }
    }

    cout << endl << "sum of signal strengths: " << sumOfSignalStrengths << endl;
}