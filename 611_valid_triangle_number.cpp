/*
https://leetcode.com/problems/valid-triangle-number/
maples1
3/4/2021
*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        int length = nums.size();
        
        for(int i=0; i<length; i++)
        {
            for (int j=i+1; j<length;j++)
            {
                for(int k = j+1; k<length;k++)
                {
                    if ((nums[i]+nums[j]>nums[k]) 
                        && (nums[j]+nums[k]>nums[i]) 
                        && (nums[k]+nums[i]>nums[j]))
                        count ++;
                }
            }
        }
        return count;
    }
};