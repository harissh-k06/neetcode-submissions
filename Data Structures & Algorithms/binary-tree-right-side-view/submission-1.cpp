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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> result;
        while (!q.empty()){
            TreeNode* rightSide = nullptr;
            int size = q.size();
            for (int i = 1 ; i <= size ; i++){
                TreeNode* currNode = q.front();
                q.pop();
                if (currNode){
                    rightSide = currNode;
                    q.push(currNode->left);
                    q.push(currNode->right);
                }
            }
            if (rightSide){
                result.push_back(rightSide->val);
            }
        }
        return result;
    }
};
