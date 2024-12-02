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
as part 1 but save head and tails in vector

when looping to check distance chek every one of them by using the element before as head
    {head, tail1, tail2}
    when checking tail1 head is head, whle checking tail2 tail1 is considered as the head

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
    set<coords> positionsVisited = {};
    vector<coords> rope = {};

    // populate rope vector with 10 elements
    for (int _ = 0; _ < 10; _++) {
        rope.push_back(make_tuple(0, 0));
    }


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

            vector<string> splittedLine = splitStr(line, " ");

            coords moveHead = movements[splittedLine[0]]; // vector of movement
            int nMovements = stoi(splittedLine[1]);

            cout << splittedLine[0] << ", " << splittedLine[1] << endl;

            // do n repetitions of line[2] to move head
            while (nMovements--) {
                for (int i = 0; i < rope.size(); ++i) { // do not calculate last one as head

                    coords &headPos = rope[i];
                    coords &tailPos = rope[i + 1];

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
                    }
                    // cout << "tail: " << get<0>(tailPos) << ", " << get<1>(tailPos) << endl;

                }

                positionsVisited.insert( rope[rope.size() - 1] );
            }
    
        }
        myfile.close();
    }
    else { cout << "file not found" << endl; }


    cout << "number of position visited: " << positionsVisited.size() << endl;

    for (auto& i : positionsVisited) {
        cout << get<0>(i) << ", " << get<1>(i) << endl;
        
    }

}