#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;  // Add this line

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            unordered_set<char> check_row;
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.' && check_row.find(board[row][col]) != check_row.end()) {
                    return false;
                }
                check_row.insert(board[row][col]);
            }
        }

        for (int col = 0; col < 9; col++) {
            unordered_set<char> check_col;
            for (int row = 0; row < 9; row++) {
                if (board[row][col] != '.' && check_col.find(board[row][col]) != check_col.end()) {
                    return false;
                }
                check_col.insert(board[row][col]);
            }
        }

        vector<unordered_set<char>> check_subbox(9);
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                int loc = (row / 3) * 3 + col / 3;
                if (board[row][col] != '.' && check_subbox[loc].find(board[row][col]) != check_subbox[loc].end()) {
                    return false;
                }
                check_subbox[loc].insert(board[row][col]);
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board(9, vector<char>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    Solution solution;
    if (solution.isValidSudoku(board)) {
        cout << "Valid Sudoku board." << endl;
    } else {
        cout << "Invalid Sudoku board." << endl;
    }

    return 0;
}
