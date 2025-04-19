#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    unordered_set<int> cols;
    unordered_set<int> diag;
    unordered_set<int> antiDiag;

    void solve(vector<string> &board, int row, vector<vector<string>> &res, int n) {
        if (row >= n) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            int diagonal = row + col;
            int antiDiagonal = row - col;
            if (cols.find(col) != cols.end() || diag.find(diagonal) != diag.end() || antiDiag.find(antiDiagonal) != antiDiag.end()) {
                continue;
            }
            board[row][col] = 'Q';
            diag.insert(diagonal);
            antiDiag.insert(antiDiagonal);
            cols.insert(col);

            solve(board, row + 1, res, n);

            board[row][col] = '.';
            diag.erase(diagonal);
            antiDiag.erase(antiDiagonal);
            cols.erase(col);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        solve(board, 0, res, n);
        return res;
    }
};

int main() {
    Solution s;
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<string>> solutions = s.solveNQueens(n);

    cout << "Total solutions: " << solutions.size() << "\n\n";
    for (auto &board : solutions) {
        for (auto &row : board) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
