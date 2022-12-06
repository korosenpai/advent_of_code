#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm> // max_element
#include <iterator>  // distance
using namespace std;

int main() {
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int typePrioritySum = 0;

    vector<string> threeLines =  {}; // vector to hold the three lines to examine
    string line;

    ifstream myfile ("inp.in");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            threeLines.push_back(line);

            if (threeLines.size() == 3) {
                
                // loop for all chars in first string and check if in all others
                for(int c = 0; c < threeLines[0].length(); c++) {

                    // found char in other strings
                    if (
                            threeLines[1].find(threeLines[0][c]) != string::npos &&
                            threeLines[2].find(threeLines[0][c]) != string::npos 
                        ) {

                        typePrioritySum += letters.find(threeLines[0][c]) + 1;
                        break;
                    }
                }

                threeLines.clear(); // reset vector
            }

        }
    }

    cout << typePrioritySum << endl;
}