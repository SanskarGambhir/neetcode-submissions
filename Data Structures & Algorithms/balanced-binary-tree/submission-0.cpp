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
    bool ans = true;

    bool isBalanced(TreeNode* root) {
        findDepth(root);
        return ans;
    }

    int findDepth(TreeNode* root){
        TreeNode* temp = root;

        if(temp==nullptr){
            return 0;
        }

        int leftMax = findDepth(temp->left);
        int rightMax = findDepth(temp->right);

        if(leftMax>rightMax+1 || rightMax>leftMax+1){
            ans = false;
        }

        return 1+max(leftMax, rightMax);
    }
};
