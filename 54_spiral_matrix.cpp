/*
https://leetcode.com/problems/spiral-matrix/
maples1
1/19/2023
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /* Get the spiral by going around the borders of the 
        * matrix. At the completion of each edge, reduce the 
        * boundaries of the rectangle so the items on that 
        * edge will not be counted again.
        * Break when one set of opposing boundaries cross one 
        * another.
        */

        // Left and right boundaries
        int left = 0, right = matrix[0].size() - 1;
        // Top and bottom boundaries
        int top = 0, bottom = matrix.size() - 1;
        vector<int> result;

        // Start at 0,0
        // Go right until the edge is hit
        while(1)
        {
            int i, j; // iterators

            // add the top border
            i = top;
            for (j = left; j <= right; j++)
            {
                result.push_back(matrix[i][j]);
            }
            // compress rectangle and check if spiral is complete
            top++;
            if (top > bottom) break;


            // add the right border
            j = right;
            for (i = top; i <= bottom; i++)
            {
                result.push_back(matrix[i][j]);
            }
            right--;
            if (left > right) break;

            // add the bottom border
            i = bottom;
            for (j = right; j >= left; j--)
            {
                result.push_back(matrix[i][j]);
            }
            bottom--;
            if (top > bottom) break;

            // add the left border
            j = left;
            for(i = bottom; i >= top; i--)
            {
                result.push_back(matrix[i][j]);
            }
            left++;
            if (left > right) break;
        }
        return result;
    }
};