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
    bool result = true;

    bool isBalanced(TreeNode* root) {
        checkBalanced(root);
        return result;
    }

    int checkBalanced(TreeNode* root){
        if(root==nullptr){
            return 0;
        }

        int leftDepth = checkBalanced(root->left);
        int rightDepth = checkBalanced(root->right);

        if(leftDepth-rightDepth>1 || rightDepth-leftDepth>1){
            result = false;
        }

        return 1+max(leftDepth, rightDepth);
    }
};
