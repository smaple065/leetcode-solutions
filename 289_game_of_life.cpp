/*
https://leetcode.com/problems/game-of-life/
maples1
1/16/2023
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // Compare each item to its neighbors
        // put board[m][n] through the rules and determine its next state
        // assign board[m][n] to its next state

        // Idea: Brute force. 
        // Create vector<vector<int>> where each row is 
        // [i][0], [i][1] a set of indices corresponding to a cell
        // that will be updated and [i][2] the new value of that cell

        int mCt = board.size(), nCt = board[0].size();

        vector<vector<int>> toChange;

        // Iterate through each cell of the board
        // Iterate rows
        for (int m = 0; m < mCt; m++)
        {
            // iterate columns
            for (int n = 0; n < nCt; n++)
            {
                // Get neighbors
                vector<int> neighbors;

                // go up
                if (m-1 >= 0)
                {
                    neighbors.push_back(board[m-1][n]);

                    // go left
                    if (n-1 >= 0)
                        neighbors.push_back(board[m-1][n-1]);
                    // go right
                    if (n+1 < nCt)
                        neighbors.push_back(board[m-1][n+1]);
                }
                // go down
                if (m+1 < mCt)
                {
                    neighbors.push_back(board[m+1][n]);

                    // go left
                    if (n-1 >= 0)
                        neighbors.push_back(board[m+1][n-1]);
                    // go right
                    if (n+1 < nCt)
                        neighbors.push_back(board[m+1][n+1]);
                }

                // horizontal neighbors
                // go left
                if (n-1 >= 0)
                    neighbors.push_back(board[m][n-1]);
                // go right
                if (n+1 < nCt)
                    neighbors.push_back(board[m][n+1]);

                int next = determineState(board[m][n], neighbors);

                if (next != board[m][n])
                    toChange.push_back({m, n, next});
            }
        }

        for (auto e : toChange)
        {
            // get coordinates to replace
            int m = e[0], n = e[1];
            // get new state
            int st = e[2];

            board[m][n] = st;
        }
    }

    // determineState counts a cell's neighboring live cells and uses
    // that count to determine its state in the next generation
    // Inputs: value of a cell, list of neighbors' values
    // Output: What state the cell will be in the next gen
    int determineState(int cell, vector<int>& neighbors)
    {
        int liveCt = 0;
        // count live neighbors
        for (auto i : neighbors)
        {
            if (1 == i)
            {
                liveCt++;

                // stop counting if there are already more than three
                if (liveCt > 3)
                    break;
            }
        }

        //
        // Apply rules
        //

        // Any live cell with fewer than two live neighbors dies
        // Any live cell with more than three live neighbors dies
        if (cell && ((liveCt < 2) || (liveCt > 3)))
        {
            return 0;
        }
        // Any live cell with two or three live neighbors lives
        else if (cell && (2 == liveCt || 3 == liveCt))
        {
            return 1;
        }
        // Any dead cell with exactly three live neighbors becomes a live cell
        else if (!cell && (3 == liveCt))
        {
            return 1;
        }
        else return cell;
    }
};