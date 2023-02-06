/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/
maples1
1/31/2023
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        /*
        * First solution idea: Traverse the tree and copy it into a vector.
        * Find the kth smallest element in the vector
        */
        vector<int> victor;

        traverse(victor, root);

        return victor[k-1];
    }

    void traverse(vector<int>& nodelist, TreeNode* cur)
    {
        if (cur != nullptr)
        {
            traverse(nodelist,cur->left);
            nodelist.push_back(cur->val);
            traverse(nodelist, cur->right);
        }
    }
};