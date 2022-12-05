#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
    // part 1

    int highestCal = 0;
    int calories = 0;
    string line;

    ifstream myfile ("inp.in");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {

            // empty line
            if (line == "") {
                highestCal = max(highestCal, calories);
                calories = 0;
            }
            else {
                calories += stoi(line);
            }
        }
        myfile.close();
    }

    cout << highestCal << endl;    

}