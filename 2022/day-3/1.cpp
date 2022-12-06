#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main() {
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int typePrioritySum = 0;

    string line;
    ifstream myfile ("inp.in");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {

            string firstHalf = line.substr(0, line.length()/2);
            string secondHalf = line.substr(line.length()/2); // if line is odd, second half will be greater, search from second half

            // cout << "\t" << firstHalf << "\t" << secondHalf << endl;
            for(int c = 0; c < secondHalf.length(); c++) {

                // found char in other string
                if (firstHalf.find(secondHalf[c]) != string::npos) {
                    // cout << secondHalf[c] << "\t" << letters.find(secondHalf[c]) << endl;
                    typePrioritySum += letters.find(secondHalf[c]) + 1;
                    break;
                }

            }

        }
        myfile.close();
    }

    cout << typePrioritySum << endl;
    
}