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
    int diameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        diameterFunction(root);
        return diameter;
    }

    int diameterFunction(TreeNode* root){
        if(root==nullptr){
            return 0;
        }

        int leftDepth = diameterFunction(root->left);
        int rightDepth = diameterFunction(root->right);

        diameter = max(diameter, leftDepth + rightDepth);

        return 1+max(leftDepth, rightDepth);
    }
};
