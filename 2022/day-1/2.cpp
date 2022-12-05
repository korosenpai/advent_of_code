#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {
    // part 1

    vector<int> highestCal = {0, 0, 0};
    int calories = 0;
    string line;

    ifstream myfile ("inp.in");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {

            // empty line
            if (line == "") {
                // highestCal = max(highestCal, calories);
                highestCal.push_back(calories);

                // Find the minimum element from the array and remove
                highestCal.erase(min_element(highestCal.begin(), highestCal.end()));

                calories = 0;
            }
            else {
                calories += stoi(line);
            }
        }
        myfile.close();
    }

    cout << accumulate(highestCal.begin(), highestCal.end(), 0);

}