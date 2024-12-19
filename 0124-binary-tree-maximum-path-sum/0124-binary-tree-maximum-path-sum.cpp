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
    int maximum(TreeNode*root, int &maxi){
        if(root==NULL)return 0;
        int maxlh=max(0,maximum(root->left,maxi));
        int maxrh=max(0,maximum(root->right,maxi));
        maxi=max(maxi,maxlh+maxrh+root->val);
        return (root->val)+max(maxlh,maxrh);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maximum(root,maxi);
        return maxi;
        
    }
};