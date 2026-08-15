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
    vector<int>ans;
    void rightView(TreeNode* root, int level){
        if(!root)return;

        if(level == ans.size())ans.push_back(root->val);
        if(root->right)rightView(root->right,level+1);
        if(root->left)rightView(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        rightView(root,0);
        return ans;
    }
};