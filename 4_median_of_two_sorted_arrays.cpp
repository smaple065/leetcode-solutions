/*
https://leetcode.com/problems/median-of-two-sorted-arrays/
maples1
5/23/2022
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /* given nums1[m] and nums2[n] return the median of the two sorted arrays
        median - middle number in a list
        */
        
        int i = 0, j = 0, k = 0;    // iterators for each array
        int m = nums1.size(),       // size of nums1
            n = nums2.size();       // size of nums2
        int medIndex;               // index of median
        int totalNums;              // combined number of elements in arrays
        bool isEven;                // even/oddness of combined arrays
        float mid;                  // combined center of arrays
        double median;              // median to return
        
        totalNums = m + n;
        isEven = (totalNums % 2 == 0);
        mid = float(totalNums)/2;
        if (!isEven) mid += 0.5;
        
        int cur, prev;
        // get that median
        while(k <= mid)
        {
            // if nums1 has run out and nums2 has not
            if ((i == m) && (j < n))
            {
                cur = nums2[j];
                j++;
            }
            // if nums 2 has run out and nums 1 has not
            else if ((i < m)&&(j == n))
            {
                cur = nums1[i];
                i++;
            }
            // if current val of nums1 is less than or equal to 
            // current val of nums 2
            else if (nums1[i] <= nums2[j])
            {
                cur = nums1[i];
                i++;
            }
            // if current val of nums2 is less than or equal to 
            // current val of nums 1 
            else
            {
                cur = nums2[j];
                j++;  
            }
            
            // break early if is odd
            if (((k+1) == mid) && !isEven)
            {
                median = cur;
                break;
            }
            else if ((k == mid) && isEven)
            {
                median = ((float(prev) + float(cur)) / 2);
                
            }
            
            // iterate
            prev = cur;
            k++;
        }
        
        return median;       
    }
};