#include<bits/stdc++.h>
using namespace std;

/*
* @Author: [Nishi Kumari]

* @Problem: 

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
*/

/*
* @Solution :

Approach 1 # Brute Force Approach

Intuition:
We validate each row, column, and 3 x 3 sub-grid separately by iterating through the board multiple times. For each row, column, and sub-grid, we use a hash set to track visited numbers and ensure no repetitions occur.

Approach:
1.Check each row for duplicates using a hash set.
2.Check each column for duplicates using a hash set.
3.Divide the board into 3 x 3 sub-boxes and validate each box using a hash set.

- Time Complexity:
𝑂(𝑛^2) for traversing rows, columns, and sub-boxes.

- Space Complexity:
O(n) for the hash set used in each check.


*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows
        for (int i = 0; i < 9; i++) {
            unordered_set<char> seen;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (seen.count(board[i][j])) return false;
                    seen.insert(board[i][j]);
                }
            }
        }

        // Check columns
        for (int j = 0; j < 9; j++) {
            unordered_set<char> seen;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    if (seen.count(board[i][j])) return false;
                    seen.insert(board[i][j]);
                }
            }
        }

        // Check 3x3 sub-boxes
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                unordered_set<char> seen;
                for (int i = boxRow; i < boxRow + 3; i++) {
                    for (int j = boxCol; j < boxCol + 3; j++) {
                        if (board[i][j] != '.') {
                            if (seen.count(board[i][j])) return false;
                            seen.insert(board[i][j]);
                        }
                    }
                }
            }
        }

        return true;
    }
};

/*
Approach 2 # Optimized approach (Using Separate Sets for Rows, Columns, and Sub-boxes)

Intuition:
Instead of validating rows, columns, and sub-boxes separately in multiple iterations, we can use three hash sets for each row, column, and sub-box, checking validity in a single pass through the board.

Approach:
1.Create three 2D arrays of hash sets to track visited numbers for rows, columns, and sub-boxes.
2.Traverse the board once, and for each cell:
    - Check if the number exists in the corresponding row, column, or sub-box set.
    - If it does, the board is invalid. Otherwise, add it to the sets.

- Time Complexity:
O(n^2), single pass through the board.

- Space Complexity:
O(n^2), space for hash sets.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    char num = board[i][j];
                    int boxIndex = (i / 3) * 3 + j / 3;

                    // Check for duplicates
                    if (rows[i].count(num) || cols[j].count(num) || boxes[boxIndex].count(num)) {
                        return false;
                    }

                    // Add to sets
                    rows[i].insert(num);
                    cols[j].insert(num);
                    boxes[boxIndex].insert(num);
                }
            }
        }

        return true;
    }
};

/*
Approach 3 # Best approach ( Using Bitmasking for Space Optimization)

Intuition:
We can replace the hash sets with bit masks, where each bit in an integer represents whether a number 
1−9 is present in a row, column, or sub-box. This reduces the space complexity.

Approach:
1.Use three arrays of integers for rows, columns, and sub-boxes.
2.For each cell:
    - Compute the bitmask for the current number.
    - Check if the bit is already set in the corresponding row, column, or sub-box integer.
    - If it is, return false. Otherwise, update the integers by setting the bit.

3.Return true if no duplicates are found.

- Time Complexity:
O(n^2), single pass through the board.

- Space Complexity:
O(n), for the integers used.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9, 0), cols(9, 0), boxes(9, 0);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int mask = 1 << num;
                    int boxIndex = (i / 3) * 3 + j / 3;

                    // Check for duplicates
                    if ((rows[i] & mask) || (cols[j] & mask) || (boxes[boxIndex] & mask)) {
                        return false;
                    }

                    // Update masks
                    rows[i] |= mask;
                    cols[j] |= mask;
                    boxes[boxIndex] |= mask;
                }
            }
        }

        return true;
    }
};

/*
Approach 4 # 

Intuition
My initial thoughts are to maintain sets or arrays to keep track of the digits in each row, column, and 3x3 subgrid to validate the rules of Sudoku.

Approach
1.Initialize three 2D boolean arrays (row, col, subGrid) to keep track of digits encountered in each row, each column, and each 3x3 subgrid.
    - Example:
       - row[r][d] is true if digit d+1 is already present in the r-th row.
       - col[c][d] is true if digit d+1 is already present in the c-th column.
       - subGrid[g][d] is true if digit d+1 is already present in the g-th 3x3 subgrid.

2.Iterate through each cell in the Sudoku board.
    - Skip empty cells represented by dots ('.').
    - Convert the character digit to a numerical index (idx) by subtracting the ASCII value of '0' and subtracting 1.
        - Example: If board[r][c] is '5', idx will be 4.
    - Determine the subgrid number (gridNum) based on the current cell's position.
        - Example: If r = 4 and c = 7, then gridNum will be 5.

3. Check if the digit is already present in the corresponding row, column, or subgrid.
    - If row[r][idx], col[c][idx], or subGrid[gridNum][idx] is true, return false as it violates the Sudoku rules.

4. Update the boolean arrays for the current row, column, and subgrid with the current digit.
    - Set row[r][idx], col[c][idx], and subGrid[gridNum][idx] to true.

5. If the iteration completes without returning false, the Sudoku board is valid, and the function returns true.

- Time complexity: 
O(1) since the size of the Sudoku board is fixed.

- Space complexity:
O(1) as the size of the Sudoku board is constant, and the arrays have fixed dimensions.

*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int num = 9;
        // Initialize boolean arrays to track digits in each row, column, and subgrid
        bool row[num][num] = {false};
        bool col[num][num] = {false};
        bool subGrid[num][num] = {false};
        
        // Iterate through each cell in the Sudoku board
        for(int r = 0; r < num; ++r){
            for(int c = 0; c < num; ++c){
                // Skip empty cells
                if(board[r][c] == '.')
                    continue; // if not a number, proceed to the next cell
                
                // Convert character digit to numerical index
                int idx = board[r][c] - '0' - 1; // char to num idx
                // Determine the subgrid number based on the current cell's position
                int gridNum = (r/3) * 3 + (c/3);
                
                // Check if the number already exists in the corresponding row, column, or subgrid
                if(row[r][idx] || col[c][idx] || subGrid[gridNum][idx]){
                    return false; // if duplicate number found, the Sudoku board is invalid
                }
                
                // Update the boolean arrays for the current row, column, and subgrid with the current digit
                row[r][idx] = true;
                col[c][idx] = true;
                subGrid[gridNum][idx] = true;
            }
        }
        return true; // if no duplicates found, the Sudoku board is valid
    }
};
