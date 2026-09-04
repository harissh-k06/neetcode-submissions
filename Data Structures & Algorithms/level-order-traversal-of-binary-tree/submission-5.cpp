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

private:
    void helper(TreeNode* root ,vector<vector<int>>& result, int level){
        if (!root) return;
        if (result.size()==0 || level > result.size() - 1) {
            vector<int> currentLevel;
            currentLevel.push_back(root->val);
            result.push_back(currentLevel);
            int newLevel = level + 1;
            helper(root->left , result , newLevel);
            helper(root->right , result , newLevel);
        }else{
            int newLevel = level + 1;
            result[level].push_back(root->val);
            helper(root->left , result , newLevel);
            helper(root->right , result , newLevel);
        }
        return;
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        helper(root , result , 0);
        return result;
    }
};