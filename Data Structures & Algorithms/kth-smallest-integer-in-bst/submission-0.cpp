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
    vector<int> nodeValues;

    int kthSmallest(TreeNode* root, int k) {
        inorderTraversal(root);

        return nodeValues[k-1];
    }

    void inorderTraversal(TreeNode* root){
        if(root==nullptr){
            return;
        }

        inorderTraversal(root->left);
        nodeValues.push_back(root->val);
        inorderTraversal(root->right);
    }
};