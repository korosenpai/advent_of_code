#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

/*
n1-n2
z1-z2

numbers contained if:
    - n1 <= z1 && n2 >= z2 and viceversa

n1 assign to major interval (only that one can contain the other)
n2 - n1 >= z2 - z1

these intervals will be one less from number of digits present, then add +1

*/

// https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/
vector<string> split(string str, const char* sep) {
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

vector<int> strToInt(vector<string> vec) {
    // convert all elements of vector from string to int
    vector<int> newVector = {};

    for (int i = 0; i < vec.size(); ++i) {
        newVector.push_back(stoi(vec[i]));
    }

    return newVector;
}

int main() {
    vector<string> pairs = {};
    int faultyPairs = 0;

    string line;
    ifstream myfile ("inp.in");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            
            pairs = split(line, ",");

            vector<int> firstPair = strToInt(split(pairs[0], "-"));
            vector<int> secondPair = strToInt(split(pairs[1], "-"));


            // check if either one of the pairs is englobinig the other
            if (
                ( firstPair[0] <= secondPair[0] && secondPair[1] <= firstPair[1] ) ||
                ( secondPair[0] <= firstPair[0] && firstPair[1] <= secondPair[1] )
            ) {
                faultyPairs++;
            }

            pairs.clear();
        }
        myfile.close();
    }

    cout << faultyPairs << endl;
}