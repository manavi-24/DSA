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
    vector<vector<int>>levelorder(TreeNode*root){
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>res;
            for(int i=0; i<size; i++){
                TreeNode*node=q.front();
                res.push_back(node->val);
                q.pop();
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            ans.push_back(res);
            
        }
        return ans;
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>rsv;
        vector<vector<int>>lvl=levelorder(root);
        for(auto i:lvl){
            rsv.push_back(i.back());
        }
        return rsv;

        
    }
};