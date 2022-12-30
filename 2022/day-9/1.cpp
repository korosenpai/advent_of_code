#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <tuple>
#include <map>
#include <vector>
#include <cstdlib> // abs
#include <cstring> // strtok
using namespace std;

/*

position of head and tail indicated by coordinates

move head n times requested by vector of U, D, L, R
if head is far from tail and not touching it ->
    tail must go in the position the head was before moving (deduction from input and problem explanation) 
    
    insert then coords of tail in set so duplicates get remove automatically ->
        size of that set is number of unique places visited

*/


typedef tuple<int, int> coords; // coordinates

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

int main() {
    coords headPos = make_tuple(0, 0);
    coords tailPos = headPos;
    set<coords> positionsVisited = { tailPos };

    map<string, coords> movements = {
        { "L",  make_tuple(-1, 0) }, // tuple is -> x, y
        { "R",  make_tuple(1, 0) },
        { "U",  make_tuple(0, 1) },
        { "D",  make_tuple(0, -1) },
    };

    string line;

    
    ifstream myfile ("inp.in");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) { // line is the instruction
            // cout << line[0] << ", " << line[2] << endl;

            vector<string> splittedLine = splitStr(line, " ");

            coords moveHead = movements[splittedLine[0]]; // vector of movement
            int nMovements = stoi(splittedLine[1]);

            // do n repetitions of line[2] to move head
            while (nMovements--) {
                coords oldHeadPos = headPos; // to save where head was before moving it for tail

                get<0>(headPos) += get<0>(moveHead);
                get<1>(headPos) += get<1>(moveHead);
                // cout << "head: " << get<0>(headPos) << ", " << get<1>(headPos) << endl;


                // move tail only if distant from head
                // if head is out of range ( distance of two ore more ) in any case move tail to where head was before moving
                if (
                    abs(get<0>(headPos) - get<0>(tailPos)) > 1 ||
                    abs(get<1>(headPos) - get<1>(tailPos)) > 1
                ) {
                    // move tail from where head was before
                    tailPos = oldHeadPos;
                    positionsVisited.insert(tailPos);
                }
                // cout << "tail: " << get<0>(tailPos) << ", " << get<1>(tailPos) << endl;

            }
    
        }
        myfile.close();
    }
    else { cout << "file not found" << endl; }


    cout << "number of position visited: " << positionsVisited.size() << endl;

}