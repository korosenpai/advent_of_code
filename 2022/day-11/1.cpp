#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


int main() {
    string line;
    vector<string> monkeyData = {};
    
    ifstream myfile ("inp.in");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            if (line == "") { continue; }
    
            monkeyData.push_back(line);

            if (monkeyData.size() != 6) { continue; }

            for (int i = 0; i < monkeyData.size(); ++i) {
                cout << monkeyData[i] << endl;
            }

            cout << "---" << endl;
            monkeyData = {};
            
    
        }
        myfile.close();
    }
    else { cout << "file not found" << endl; }
}