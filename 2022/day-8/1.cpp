#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm> // max_element
using namespace std;

/*
forest = {
    { 3, 0, 3, 7, 3 },
    { 2, 5, 5, 1, 2 },
    { 6, 5, 3, 3, 2 },
    { 3, 3, 5, 4, 9 },
    { 3, 5, 3, 9, 0 }
}

check if tree is visible:
    - on the edge
    - highest number in at least one direction

skip first and last line
skip first and last numbers in line

// not very efficient way but works
for all numbers remaining ->
    loop and get arrays of numbers that are on top, left, right, bottom and check if they are
    the max of at least one of those arrays -> means that tree is visible


*/

int main() {
    
    vector<vector<int>> forest = {};

    // get all forest data
    string line;
    ifstream myfile ("inp.in");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            vector<int> convertedLine = {};
            
            // convert line to vector of ints
            for(int c = 0; c < line.length(); c++) {
                convertedLine.push_back(line[c] - '0'); // - 0 is to convert char to int
            }

            forest.push_back(convertedLine);
        }
        myfile.close();
    }
    else { cout << "file not found" << endl; }

    // start with trees that will not be included in loop (outer ones)
    // those are by default visible
    // it is a square
    int visibleTrees = 4 * (forest.size() - 1);


    for (int line = 1; line < forest.size() - 1; ++line) { // 1 and -1 to exclude first and last

        for(int tree = 1; tree < forest[line].size() - 1; tree++) {
            
            int treeHeight = forest[line][tree];

            // slice lists based on position
            vector<int> posLeft( forest[line].begin(), forest[line].begin() + tree );
            vector<int> posRight( forest[line].begin() + tree + 1, forest[line].end() );


            bool isVisibleOnLeft = *max_element(posLeft.begin(), posLeft.end()) < treeHeight;
            bool isVisibleOnRight = *max_element(posRight.begin(), posRight.end()) < treeHeight;

            // separate returns because to get postop and bottom we do a lot of processing
            if (isVisibleOnLeft || isVisibleOnRight) {
                visibleTrees++;
                continue;
            }

            vector<int> posTop = {};
            vector<int> posBottom = {};

            for (int i = 0; i < forest.size(); ++i) {
                if (i < line) {
                    posTop.push_back(forest[i][tree]);
                }
                else if (i != line) {
                    posBottom.push_back(forest[i][tree]);
                }
            }


            bool isVisibleOnTop = *max_element(posTop.begin(), posTop.end()) < treeHeight;
            bool isVisibleOnBottom = *max_element(posBottom.begin(), posBottom.end()) < treeHeight;

            if (isVisibleOnTop || isVisibleOnBottom) {
                visibleTrees++;
                continue;
            }

        }
    }

    cout << "visible trees: " << visibleTrees << endl;
}