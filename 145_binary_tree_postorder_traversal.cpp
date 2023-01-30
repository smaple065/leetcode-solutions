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
    vector<int> postorderTraversal(TreeNode* root) {
        /*
         * Solution: Call a recursive function which pushes each node
         * to a resulting vector. Postorder traversal is done by 
         * calling the traversal on the node to the left, calling 
         * the traversal on the node to the right, then visiting the 
         * current node
        */
        
        vector<int> result;
        postOrder(result, root);

        return result; 
    }
    
    // Traverse left, traverse right, visit node
    void postOrder(vector<int>& res, TreeNode* cur)
    {
        if (cur != nullptr)
        {
            postOrder(res, cur->left);
            postOrder(res, cur->right);
            res.push_back(cur->val);

        }
    }
};