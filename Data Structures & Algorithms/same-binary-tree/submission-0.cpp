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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool result = leftRightNodesCheck(p, q);
        return result;
    }

    bool leftRightNodesCheck(TreeNode* temp1, TreeNode* temp2){
        if(temp1==nullptr && temp2==nullptr){
            return true;
        }
        if(temp1==nullptr || temp2==nullptr){
            return false;
        }
        if(temp1->val != temp2->val){
            return false;
        }

        bool leftCheck = leftRightNodesCheck(temp1->left, temp2->left);
        if(leftCheck==false){
            return false;
        }

        bool rightCheck = leftRightNodesCheck(temp1->right, temp2->right);
        if(rightCheck==false){
            return false;
        }

        return rightCheck;
    }
};
