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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=0;
        if(root==NULL)return ans;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        
        while(!q.empty()){
            long long mmin=q.front().second;
            long long size=q.size();
            long long first,last;
            for(int i=0; i<size; i++){
                long long cur_pos=q.front().second-mmin;
                TreeNode*node=q.front().first;
                q.pop();
                if(i==0)first=cur_pos;
                if(i==size-1)last=cur_pos;
                if(node->left){
                    q.push({node->left,cur_pos*2+1});
                }
                if(node->right){
                    q.push({node->right,cur_pos*2+2});
                }

            }
            ans=max(ans,last-first+1);
        }
        return ans;
        
    }
};