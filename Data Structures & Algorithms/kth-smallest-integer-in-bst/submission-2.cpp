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
        vector<int> res;
        inOrder(root , k , res);
        return res[k- 1];
    }
    void inOrder(TreeNode* node , int k , vector<int> & res){
        if (res.size()>=k || !node) return;
        inOrder(node->left , k , res);
        res.push_back(node->val);
        inOrder(node->right , k , res);
    }
};
