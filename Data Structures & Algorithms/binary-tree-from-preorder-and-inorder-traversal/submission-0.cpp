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
    int preIdx = 0 , inIdx = 0;
    TreeNode* dfs(vector<int>& preOrder, vector<int>& inOrder , int limit){
        if (preIdx >= preOrder.size()) return nullptr;
        if (inOrder[inIdx] == limit){
            inIdx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(preOrder[preIdx++]);
        root->left = dfs(preOrder , inOrder , root->val);
        root->right = dfs(preOrder, inOrder , limit);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder , inorder , INT_MAX);
    }

};
