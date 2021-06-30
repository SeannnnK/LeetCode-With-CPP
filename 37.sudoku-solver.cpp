/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (48.18%)
 * Likes:    3082
 * Dislikes: 114
 * Total Accepted:    249.9K
 * Total Submissions: 516.1K
 * Testcase Example:
 * '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * A sudoku solution must satisfy all of the following rules:
 *
 *
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 *
 *
 * The '.' character indicates empty cells.
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * Output:
 * [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * Explanation: The input board is shown above and the only valid solution is
 * shown below:
 *
 *
 *
 *
 *
 * Constraints:
 *
 *
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 * It is guaranteed that the input board has only one solution.
 *
 *
 */

// @lc code=start
// snapchat | uber

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    continue;
                }
                for (char num = '1'; num <= '9'; ++num) {
                    if (isValid(board, i, j, num)) {
                        board[i][j] = num;
                        if (solve(board)) {
                            return true;
                        } else {
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
        return true;
    }

private:
    bool isValid(vector<vector<char>>& board, int row, int col, char num)
    {
        for (int i = 0; i < 9; ++i) {
            // 1. row
            if (board[row][i] != '.' && board[row][i] == num) {
                return false;
            }
            // 2. col
            if (board[i][col] != '.' && board[i][col] == num) {
                return false;
            }
            // 3. sub-box attention the sub-box coordidate
            if (board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] != '.' &&
                board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == num) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution sol;
    sol.solveSudoku(board);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] - '0' << " ";
        }
        cout << endl;
    }
    return 0;
}
// @lc code=end
