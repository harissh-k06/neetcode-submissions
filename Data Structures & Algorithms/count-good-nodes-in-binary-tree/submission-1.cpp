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
    int goodNodes(TreeNode* root) {
        int res = 0 ; 
        dfs(root,root->val,res);
        return res;
    }

private:
    void dfs(TreeNode* root  , int maxVal , int& res ){
        if (!root) return;
        if (root->val >= maxVal) res++;
        dfs(root->left , max(maxVal , root->val) , res);
        dfs(root->right , max(maxVal , root->val) , res);

    }

};
