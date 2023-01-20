/*
https://leetcode.com/problems/valid-sudoku/
maples1
1/20/2023
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /* Pipe all rows, columns, and subsquares into
        * hash maps that track how many times each 
        * non-period character appears. If any one returns
        * a non-unique number, the board is not valid
        */

        // Put rows through validator
        for (auto row : board)
        {
            if (!isValidSubsection(row))
                return false;
        }

        // Put columns through validator
        for(int i = 0; i < 9; i++)
        {
            vector<char> col;
            for (int j = 0; j < 9; j++)
            {
                col.push_back(board[j][i]);
            }
            if (!isValidSubsection(col))
                return false;
        }

        // Put squares through validator
        for(int i = 0; i < 9; i+=3)
        {
            for (int j = 0; j < 9; j+=3)
            {
                vector<char> subSq;
                subSq.push_back(board[i][j]);
                subSq.push_back(board[i][j+1]);
                subSq.push_back(board[i][j+2]);
                subSq.push_back(board[i+1][j]);
                subSq.push_back(board[i+1][j+1]);
                subSq.push_back(board[i+1][j+2]);
                subSq.push_back(board[i+2][j]);
                subSq.push_back(board[i+2][j+1]);
                subSq.push_back(board[i+2][j+2]);

                if (!isValidSubsection(subSq))
                    return false;
            }
        }

        return true;
    }

    // Take a subsection of the sudoku board and look for 
    // duplicates. If there is a duplicate, the board is invalid.
    bool isValidSubsection(vector<char>& sub)
    {
        map<char, int> counts;

        for (auto el  : sub)
        {
            // ignore periods
            if (el != '.')
            {
                // if number doesnt exist in map, add it
                if (!counts[el])
                {
                    counts[el] = 1;
                }
                // if it does already exist, subsection is invalid
                else
                {
                    return false;
                }
            }
        }

        // return true by default
        return true;
    }
};