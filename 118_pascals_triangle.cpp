/*
https://leetcode.com/problems/pascals-triangle/
maples1
2/5/2023
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        /* Solution: iterate up to numRows, adding 
        * each row with ones in the leftmost and rightmost 
        * place. Any elements in between will be calculated 
        * from the corresponding and prior element from the 
        * above row. 
        * 
        * Triangle shifted to demonstrate array indexing:
        * 1
        * 1 1
        * 1 2 1
        * 1 3 3 1
        * 1 4 6 4 1
        */
        vector<vector<int>> results;

        // iterate down through rows
        for (int i = 1; i <= numRows; i++)
        {
            vector<int> row;
            for (int j = 0; j < i; j++)
            {
                // Add ones to the right and left sides
                if (j == 0 || j == i-1)
                {
                    row.push_back(1);
                }
                // Get sum of two numbers above and add to row
                else
                {
                    // the prior row is i-2 because the rows are
                    // 1-indexed
                    row.push_back(results[i-2][j-1]+results[i-2][j]);
                }
            }
            results.push_back(row);
        }
        return results;
    }
};