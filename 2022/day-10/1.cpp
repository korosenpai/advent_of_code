#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring> // strtok
#include <algorithm>
using namespace std;

/*

loop instruction
    add to cycle

    if interesting cycle -> add to sumOfSignalStrengths with current xregister

    if noop -> ignore

    if addx -> add new cycle (to finish the execution of instruction) and check if interesting, then add to xregister

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

    int xRegister = 1;
    int sumOfSignalStrengths = 0;
    
    

    // fill the instructions vector
    string line;
    ifstream myfile ("inp.in");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            vector<string> instr = splitStr(line, " ");

            currentCycle++;

            // current cycle is interesting cycle
            if (isInterestingCycle(currentCycle)) {
                // calculate signal strengths
                sumOfSignalStrengths += xRegister * currentCycle;
                cout << endl << xRegister << "  " << currentCycle << endl;
            }

            if (instr[0] == "addx") {
                currentCycle++;

                if (isInterestingCycle(currentCycle)) {
                    // calculate signal strengths
                    sumOfSignalStrengths += xRegister * currentCycle;
                    cout << endl << xRegister << "  " << currentCycle << endl;
                }
                xRegister += stoi(instr[1]);
            }



            instructions.push_back(line);
        }
        myfile.close();
    }
    else { cout << "file not found" << endl; }

    cout << endl << "sum of signal strengths: " << sumOfSignalStrengths << endl;
}