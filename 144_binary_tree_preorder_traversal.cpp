/*
https://leetcode.com/problems/binary-tree-preorder-traversal/
maples1
1/29/2023
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
    vector<int> preorderTraversal(TreeNode* root) {
        /*
         * Solution: Call a recursive function which pushes each node
         * to a resulting vector. Preorder traversal is done by visiting
         * the current node, then calling the traversal on the node 
         * to the left, and calling the traversal on the node to the right
        */
        
        vector<int> result;
        preOrder(result, root);

        return result;  
    }

        // Visit node, traverse left, traverse right
    void preOrder(vector<int>& res, TreeNode* cur)
    {
        if (cur != nullptr)
        {
            res.push_back(cur->val);
            preOrder(res, cur->left);
            preOrder(res, cur->right);
        }
    }
};