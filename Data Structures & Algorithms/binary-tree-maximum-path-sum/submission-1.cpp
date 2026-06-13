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
        maxSumFunction(root);
        return maxSum;
    }

    int maxSumFunction(TreeNode* temp){
        if(temp==nullptr){
            return 0;
        }

        int leftSum = maxSumFunction(temp->left);
        if(leftSum<0){
            leftSum=0;
        }

        int rightSum = maxSumFunction(temp->right);
        if(rightSum<0){
            rightSum=0;
        }

        int currentSum= leftSum + rightSum + temp->val;

        maxSum = max(maxSum, currentSum);

        return temp->val + max(leftSum, rightSum);
    }
};
