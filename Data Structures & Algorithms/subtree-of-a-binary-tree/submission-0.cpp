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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr){
            return false;
        }

        bool rootCheck = isSameTree(root, subRoot);
        if(rootCheck==true){
            return true;
        }

        bool leftTreeCheck = isSubtree(root->left, subRoot);
        if(leftTreeCheck==true){
            return true;
        }

        bool rightTreeCheck = isSubtree(root->right, subRoot);
        if(rightTreeCheck==true){
            return true;
        }

        return false;
    }

    bool isSameTree(TreeNode* temp1, TreeNode* temp2){
        if(temp1==nullptr && temp2==nullptr){
            return true;
        }
        if(temp1==nullptr || temp2==nullptr){
            return false;
        }
        if(temp1->val != temp2->val){
            return false;
        }

        bool leftCheck = isSameTree(temp1->left, temp2->left);
        if(leftCheck==false){
            return false;
        }

        bool rightCheck = isSameTree(temp1->right, temp2->right);
        if(rightCheck==false){
            return false;
        }

        return rightCheck;
    }
};
