/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current->left != NULL) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right != NULL) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // Map to track parent nodes
        markParents(root, parent_track);
        
        unordered_map<TreeNode*, bool> visited; // Map to keep track of visited nodes
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int cur_lvl = 0;

        while (!q.empty()) {
            int size = q.size();
            if (cur_lvl++ == k) break; // Stop if we've reached the desired level
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();

                // Traverse left child
                if (current->left && !visited[current->left]) {
                    q.push(current->left);
                    visited[current->left] = true;
                }

                // Traverse right child
                if (current->right && !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                }

                // Traverse parent node
                if (parent_track[current] && !visited[parent_track[current]]) {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;
    }
};