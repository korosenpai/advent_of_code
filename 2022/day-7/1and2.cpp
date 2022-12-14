#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <cstring> // strtok
#include <algorithm> // sort
using namespace std;

/*

map<string, int> dirSizes = {
    ("/", 48381165),
    ("a", 94853),
    ("e", 584),
    ("d", 24933642)
}

keep vector of dir currently in ('currentDir')
    cd / -> [/]
    cd a -> [/, //a]
    cd b -> [/, //a, //a/b]
    cd .. -> [/, //a]
    cd / -> [/]
    cd c -> [/, //c]

ignore '$ ls'
ignore 'dir dir'

if line does not start with $ and dir, split and add first element to all dirs in currentDir

PART 2

vector<int> dirSizesVec = [
    48381165,
    94853,
    584,
    24933642
]

sort in ascending order -> [
    584,
    94853,
    24933642,
    48381165
]
loop through elements and check if number >= space required -> that is number needed
space required -> update size - (totalSpace - dirSizes["/"])

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

int main() {
    map<string, int> dirSizes = {};
    vector<string> currentDir = {};
    string line;
    
    ifstream myfile ("inp.in");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            
            vector<string> lineVec = splitStr(line, " ");

            // command
            if (lineVec[0] == "$") {
                // if cd add to current dir else ignore
                if (lineVec[1] != "cd") { continue; }

                if (lineVec[2] == "..") {
                    // remove last element of currentdir -> exiting that dir
                    currentDir.pop_back();
                }
                else {
                    // create dirname of current place in dir -> to avoid if there is another dir
                    // of equal name in other dir

                    string dir = "";
                    for (int i = 0; i < currentDir.size(); ++i) {
                        dir += "/" + currentDir[i];
                    }
                    dir += lineVec[2];

                    currentDir.push_back(dir);
                    dirSizes.insert(pair<string, int>(dir, 0));
                }                
            }
            else if (lineVec[0] != "dir") {
                // file
                // add lineVec[0] to all elemns in currentDir
                for (int i = 0; i < currentDir.size(); ++i) {
                    dirSizes[currentDir[i]] += stoi(lineVec[0]);
                }
            }
        }
        myfile.close();

        // find all dirs with size <= 100000 and calculate sum
        int sumOfSmallDirs = 0;
        int maxDirSize = 100000;
        for (auto itr = dirSizes.begin(); itr != dirSizes.end(); ++itr) {
            int dirSize = itr->second;

            if (dirSize <= maxDirSize) {
                sumOfSmallDirs += dirSize;
            }
        }

        cout << sumOfSmallDirs << endl;


        //////////////// part 2 ////////////////
        
        cout << "\nPART 2" << endl;
        

        int totalSpace = 70000000;
        int spaceLeft = totalSpace - dirSizes["/"]; // unused space in disk

        int updateSize = 30000000;
        int spaceRequired = updateSize - spaceLeft;
        
        vector<int> dirSizesVec = {};

        for (auto itr = dirSizes.begin(); itr != dirSizes.end(); ++itr) {
            dirSizesVec.push_back(itr->second);
        }

        sort(dirSizesVec.begin(), dirSizesVec.end());

        for (int i = 0; i < dirSizesVec.size(); ++i) {
            // check first elem big enough
            if (dirSizesVec[i] >= spaceRequired) {
                cout << "size of dir to remove: " << dirSizesVec[i] << endl;
                break;
            }
        }


    }
    else { cout << "file not found" << endl; }
}