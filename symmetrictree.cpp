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
        bool isSymmetric(TreeNode* root) {
            return isMirror(root->left, root->right);
        }
    private:
        bool isMirror(TreeNode* n, TreeNode* m){
            if(n == nullptr && m == nullptr) return true;
            if(n == nullptr || m == nullptr) return false;
            return n->val == m->val && isMirror(n->left, m->right) && isMirror(n->right, m->left);
        }
    };