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
    TreeNode* invertTree(TreeNode* root) {
        invertTreeFunction(root);
        return root;
    }

    void invertTreeFunction(TreeNode* temp){
        if(temp==nullptr){
            return;
        }

        swap(temp->left, temp->right);
        invertTreeFunction(temp->left);
        invertTreeFunction(temp->right);
    }
};
