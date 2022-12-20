#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <vector>
using namespace std;



/*

VAR markerSize is what cahnges in the two parts -> part 1 = 4; part 2 = 14 to get results

loop all chars
add char to list
if list = 4 -> create set of chars
if set < 4 -> pop first char of list and continue
else -> list is marker
*/


int main() {
    string line;
    int markerSize = 4; // 14 for part 2
    int startOfPacketMarker = 0; // position in string of last char of marker
    vector<char> marker = {};
    
    ifstream myfile ("inp.in");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
    
            for(int c = 0; c < line.length(); c++) {
                marker.push_back(line[c]);

                if (marker.size() == markerSize) {
                    // create set and check if all different
                    set<char> markerSet(marker.begin(), marker.end());

                    // cout << "Set: ";
                    // for (int x : markerSet) {
                    //     cout << string(1, x) << " ";
                    // }
                    // cout << endl;

                    if (markerSet.size() == markerSize) {
                        // successfuly found the distinct marker

                        startOfPacketMarker = c + 1;
                        break;
                    }
                    else {
                        marker.erase(marker.begin());
                    }


                }
            }

            cout << startOfPacketMarker << endl;
    
        }
        myfile.close();
    }
    else { cout << "file not found" << endl; }
    
}