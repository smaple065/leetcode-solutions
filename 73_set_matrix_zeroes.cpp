/*
https://leetcode.com/problems/set-matrix-zeroes/
maples1
1/18/2023
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
        *   Use top and left margins as markers for which rows and
        * columns need to be filled with zeroes. Iterate through the 
        * matrix and whenever a zero is found, put a placeholder zero
        * in the leftmost spot of the row and the topmost spot of the 
        * column. Once that is done, iterate through the margins and 
        * use the markers to fill in the corresponding rows and 
        * columns with zeroes.
        * Caveat: There may be zeroes already in the margins. Store this
        * information in the end and fill in the margins at the end if 
        * needed.
        */

        bool topRowZero = false, leftColZero = false;
        int m = matrix.size();      // height
        int n = matrix[0].size();   // width

        // Check if a zero exists in the top row
        for (int i = 0; i < n; i++)
        {
            if (matrix[0][i] == 0)
            {
                topRowZero = true;
                break;
            }
        }

        // Check if a zero exists in the left column
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                leftColZero = true;
                break;
            }
        }

        // Look for zeroes in the matrix and mark
        // them in the margins
        for (int i = 1; i < m; i++) // top down
        {
            for (int j = 1; j < n; j++) // left to right
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0; // top
                    matrix[0][j] = 0; // left
                }
            }
        }

        // fill in zeroes from top margin
        for (int i = 1; i < n; i++)
        {
            if (matrix[0][i] == 0)
            {
                int j = 1;
                while(j < m)
                {
                    matrix[j][i] = 0;
                    j++;
                }
            }
        }

        // fill in zeroes from left margin
        for (int i = 1; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                int j = 1;
                while(j < n)
                {
                    matrix[i][j] = 0;
                    j++;
                }
            }
        }

        //
        // fill in top and/or left margins if needed
        //

        // fill left margin with zeroes if any were found in that column
        if (leftColZero)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }

        // fill top margin with zeroes if any were found in that row
       if (topRowZero)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[0][i] = 0;
            }
        }
    }
};