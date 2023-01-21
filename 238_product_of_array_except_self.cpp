/*
https://leetcode.com/problems/product-of-array-except-self/
maples1
1/20/2023
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /* This solution stores the products of all the 
        * numbers from left to right and from right to left.
        * The product of nums except i will be the product of
        * the left arry at i-1 and the right array at i+1
        */

        vector<int> prefix;
        vector<int> suffix;
        int len = nums.size();
        vector<int> result;

        // Allocate space for suffix sum
        // since it will be filled in backward
        for (int i = 0; i < len; i++)
        {
            suffix.push_back(0);
        }

        // fill in prefix and suffix sums
        int j = len - 1;
        int lProduct = 1, rProduct = 1;
        for (int i = 0; i < len; i++)
        {
            lProduct *= nums[i];
            prefix.push_back(lProduct);
            rProduct *= nums[j];
            suffix[j] = rProduct;

            j--;
        }

        // Calculate products except self
        for (int i = 0; i < len; i++)
        {
            if (i == 0)
            {
                result.push_back(suffix[1]);
            } 
            else if (i == (len - 1))
            { 
                result.push_back(prefix[len-2]);
            }
            else 
            {
                result.push_back(prefix[(i-1)]*suffix[(i+1)]);
            }

        }

        return result;
    }
};