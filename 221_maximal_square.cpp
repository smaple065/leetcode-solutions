/*
https://leetcode.com/problems/maximal-square/
maples1
12/17/2021
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // largest possible area, squart root of next largest area
        int lgstArea= 0, sqrt = 1;
        // height and width of matrix
        int height = matrix.size(), width = matrix[0].size();
        // height and width iterators
        int i, j;
        // if a square has been found in the current iteration
        bool found = false;
        char ch = '0'; // use for char to int conversions
                
        // look for squares
        do
        {
            found = false;
            for (i = 0; i < height; i++)
            {
                for (j = 0; j < width; j++)
                {
                    // if this is the first iteration and a 1 is found
                    if (1 == sqrt && '1' == matrix[i][j])
                    {
                        found = true;
                    }
                    // make sure a square starting at [i][j] is within bounds
                    else if ((i <= (height - 2)) && (j <= (width-2)))
                    {
                        // add up four values, they make up a complete square
                        // if they add up to four
                        int curArea = (
                            (matrix[i][j] - ch)
                            + (matrix[i][j+1] - ch)
                            + (matrix[i+1][j] - ch)
                            + (matrix[i+1][j+1] - ch));
                        if (4 == curArea)
                        {
                            found = true;
                        }
                        else 
                        {
                            matrix[i][j] = '0';
                        }
                    }
                    else
                    {
                        matrix[i][j] = '0';
                    }
                }
            }
            // reassign largest area if applicable
            if (found)
            {
                lgstArea = sqrt*sqrt;
            }
            // increment square root
            sqrt++;
        } while (found); // until we stop finding squares

        
        return lgstArea;
    }
};