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
    int maxSum = INT_MIN;

    int maxPathSum(TreeNode* root) {
        maxPathSumFunction(root);
        return maxSum;
    }

    int maxPathSumFunction(TreeNode* root){
        if(root==nullptr){
            return 0;
        }

        int leftNodesKaSum = maxPathSumFunction(root->left);
        if(leftNodesKaSum<0){
            leftNodesKaSum = 0;
        }

        int rightNodesKaSum = maxPathSumFunction(root->right);
        if(rightNodesKaSum<0){
            rightNodesKaSum=0;
        }

        int currentSum = root->val + leftNodesKaSum + rightNodesKaSum;

        maxSum = max(maxSum, currentSum);

        return root->val + max(leftNodesKaSum, rightNodesKaSum);
    }
};
