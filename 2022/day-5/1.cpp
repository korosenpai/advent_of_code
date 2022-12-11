#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm> // for 'remove'
#include <cstring> // for 'strtok'
using namespace std;

/*
store inputs in two files ->
    board.in -> board,
    inp,in -> instructions
*/


/*
architecture of board:
{   {z, n}, {m, c, d}, {p}  }

z, m, p are at the base

to move one element -> remove last element from pile, push_back() in other pile
*/
vector<vector<string>> createBoard() {
    vector<vector<string>> board = {};
    int charPerCrate = 4;
    int nCrates = 0;
    string line;
    
    ifstream myfile ("board.in");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            line += " "; // add last space to make last char 4 spaces

            // do not read last line
            if (myfile.tellg() <= 1) continue;
            
            // get number of crates
            if (nCrates == 0) {
                nCrates = (line.length() + 1) / charPerCrate; // + 1 is to add last char " "
                
                for (int n = 0; n < nCrates; n++) board.push_back({}); // create empty lists in board

            }

            // three times and get 4 chars to then add to list
            for (int n = 0; n < nCrates; n++) {
                string crate = line.substr(n * charPerCrate, charPerCrate);
                
                // remove all spaces
                crate.erase(remove(crate.begin(), crate.end(), ' '), crate.end());

                // add crate to list
                if (crate != "") {
                    // cout << "---" << crate << "---" << endl;
                    board[n].insert(board[n].begin(), crate);
                }
            }

            // cout << line << endl;
    
        }
        myfile.close();
        return board;
    }
    // file not found
    return {};
}

void printBoard(vector<vector<string>> board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int l = 0; l < board[i].size(); ++l) {
            cout << board[i][l] << endl;
        }
        cout << endl;
    }
}

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


int main() {
    vector<vector<string>> board = createBoard();
    string line;
    
    ifstream myfile ("inp.in");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
    
            vector<string> instruction = split(line, " ");

            int nCratesToMove = stoi(instruction[1]);
            int crateToMoveFrom = stoi(instruction[3]) - 1; // - 1 is for how it is stored board
            int crateToMoveTo = stoi(instruction[5]) - 1;

            for (int _ = 0; _ <= nCratesToMove - 1; _++) {
                // add value to end of crate to move to
                board[crateToMoveTo].push_back(
                    board[crateToMoveFrom][board[crateToMoveFrom].size() - 1]
                );


                // remove value from crate to move from
                board[crateToMoveFrom].pop_back();

            }
            // cout << line << endl;
        }
        myfile.close();
    }
    else { cout << "file not found" << endl; }

    // printBoard(board);

    // get final message
    string finalMsg = "";
    for (int i = 0; i < board.size(); ++i) {
        finalMsg += board[i][board[i].size() - 1][1];
    }
    cout << finalMsg << endl;
}