 #include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    
    bool isSafe(vector<string>& board, int row, int col, int n) {
        
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

         
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

         
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void nQueens(vector<string>& board, int row, int n, vector<vector<string>>& res) {
        
        if (row == n) {
            res.push_back(board);
            return;
        }

        
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';           
                nQueens(board, row + 1, n, res); 
                board[row][col] = '.';           
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        nQueens(board, 0, n, res);
        return res;
    }
};

 
int main() {
    int n = 4;
    Solution sol;
    vector<vector<string>> results = sol.solveNQueens(n);

    cout << "Found " << results.size() << " solutions for " << n << "-Queens:" << endl;
    for (const auto& solution : results) {
        for (const string& row : solution) {
            cout << row << endl;
        }
        cout << "---" << endl;
    }

    return 0;
}