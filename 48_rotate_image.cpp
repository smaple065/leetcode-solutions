/*
https://leetcode.com/problems/rotate-image/
maples1
1/20/2023
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /* One way to rotate a square is to flip it upside-down,
         * then flip the result over the hypotenuse (top left = bottom right).
         * Accomplish this through a series of element swaps.
        */

        int n = matrix.size();

        // flip matrix upside-down
        for (int i = 0; i < n; i++)
        {
            int top = 0, bottom = n-1;
            while(top < bottom)
            {
                swap(matrix[top][i], matrix[bottom][i]);

                top++;
                bottom--;
            }
        }

        // flip over hypotenuse
        int i = 0, j;
        do
        {
            j = i + 1;
            while(j != n)
            {
                swap(matrix[i][j], matrix[j][i]);
                j++;
            }
            i++;
        } while (i != n);

    }
};