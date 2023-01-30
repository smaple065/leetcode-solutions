/*
https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        /*
         * Solution: Call a recursive function which pushes each node
         * to a resulting vector. Inorder traversal is done by calling
         * the traversal on the node to the left, visiting the node, 
         * and calling the traversal on the node to the right
        */
        
        vector<int> result;
        inOrder(result, root);

        return result;   
    }

    // Visit left, visit node, visit right
    void inOrder(vector<int>& res, TreeNode* cur)
    {
        if (cur != nullptr)
        {
            inOrder(res, cur->left);
            res.push_back(cur->val);
            inOrder(res, cur->right);
        }
    }
};