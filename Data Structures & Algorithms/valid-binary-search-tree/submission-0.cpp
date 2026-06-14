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

    bool isValidBST(TreeNode* root) {
        validBstFunction(root, LONG_MIN, LONG_MAX);

        return result;
    }

    void validBstFunction(TreeNode* temp, long minRange, long maxRange){
        if(temp==nullptr){
            return;
        }

        if(temp->val<=minRange || temp->val>=maxRange){
            result = false;
            return;
        }

        validBstFunction(temp->left, minRange, temp->val);
        validBstFunction(temp->right, temp->val, maxRange);
    }
};