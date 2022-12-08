#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <numeric> //std::iota
#include <algorithm>
using namespace std;

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

// https://stackoverflow.com/questions/29419922/fastest-way-to-find-out-if-two-sets-overlap
template<class InputIt1, class InputIt2>
bool doesSetsIntersect(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
    while (first1 != last1)
        if (binary_search(first2, last2, *first1++))
            return true;
    return false;
}

int main() {
    vector<string> pairs = {};
    int faultyPairs = 0;

    string line;
    ifstream myfile ("inp.in");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            
            pairs = split(line, ",");

            
            // create set with range of both lines and see if there is an intersection
            vector<int> firstPair = strToInt(split(pairs[0], "-"));
            vector<int> secondPair = strToInt(split(pairs[1], "-"));

            // create empty sets with length of interval of numbers
            vector<int> firstSet(firstPair[1] - firstPair[0] + 1);
            vector<int> secondSet(secondPair[1] - secondPair[0] + 1);

            // populate sets with range
            iota(begin(firstSet), end(firstSet), firstPair[0]); // start from firstPair[0]
            iota(begin(secondSet), end(secondSet), secondPair[0]);


            // check if sets have intersections
            if (doesSetsIntersect(begin(firstSet), end(firstSet), begin(secondSet), end(secondSet))) {
                faultyPairs++;
            }


            pairs.clear();
        }
        myfile.close();
    }

    cout << faultyPairs << endl;
}