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

    bool traverseWithLimits(TreeNode* root , int low , int high){
        if (!root) return true;
        if (!validateRoot(root , low , high)) return false;
        return traverseWithLimits(root -> left , low,root->val) && traverseWithLimits(root -> right , root->val,high);
    }

    bool validateRoot(TreeNode* root , int lower , int upper){
        if (root -> val < upper && root-> val > lower) return true;
        else return false;
    }

public:
    bool isValidBST(TreeNode* root) {
        int low = INT_MIN , high = INT_MAX;
        return traverseWithLimits(root , low , high);
    }
};
