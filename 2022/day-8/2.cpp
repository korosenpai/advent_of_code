#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm> // reverse
using namespace std;

/*

to make it easier to loop the trees to check we put them in var surroundingTrees
    the ones from left and top are reversed to be the closest elem to tree first
    {
        {left (reversed)}
        {right}
        {top (reversed)}
        {bottom}
    }

loop surroundingTrees and simply calculate the score and if its bigger than max found before update

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


    int maxScenicScore = 0;

    for (int line = 1; line < forest.size() - 1; ++line) { // 1 and -1 to exclude first and last

        for(int tree = 1; tree < forest[line].size() - 1; tree++) {
            int treeHeight = forest[line][tree];

            // slice lists based on position
            vector<vector<int>> surroundingTrees = {{}, {}, {}, {}}; // save all one one array to simplify loop // we have to check everyone in any case
            surroundingTrees[0] = { forest[line].begin(), forest[line].begin() + tree }; // from left
            reverse(surroundingTrees[0].begin(), surroundingTrees[0].end()); // reverse to get first elements closer to current tree

            surroundingTrees[1] = { forest[line].begin() + tree + 1, forest[line].end() }; // from right

            for (int i = 0; i < forest.size(); ++i) {
                if (i < line) {
                    surroundingTrees[2].push_back(forest[i][tree]); // top
                }
                else if (i != line) {
                    surroundingTrees[3].push_back(forest[i][tree]); // bottom
                }
            }
            reverse(surroundingTrees[2].begin(), surroundingTrees[2].end()); // reverse top


            // loop in tree and calculate scenic score
            int scenicScore = 1;
            for (int i = 0; i < surroundingTrees.size(); ++i) {
                int nTrees = 0;
                for (int l = 0; l < surroundingTrees[i].size(); ++l) {
                    nTrees++;

                    if (surroundingTrees[i][l] >= treeHeight) {
                        break;
                    }
                }

                scenicScore *= nTrees;

            }
            
            // check if this trees scenic score is bigger
            if (scenicScore > maxScenicScore) { maxScenicScore = scenicScore; }


        }
    }

    cout << maxScenicScore << endl;
    
}