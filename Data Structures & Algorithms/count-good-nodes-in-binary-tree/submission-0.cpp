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
    int goodNodesCount = 0;

    int goodNodes(TreeNode* root) {
        int maxElement = INT_MIN;
        countGoodNodes(root, maxElement);
        return goodNodesCount;
    }

    void countGoodNodes(TreeNode* temp, int maxElement){
        if(temp==nullptr){
            return;
        }

        if(maxElement <= temp->val){
            goodNodesCount += 1;
            maxElement = temp->val;
        }

        countGoodNodes(temp->left, maxElement);
        countGoodNodes(temp->right, maxElement);
    }
};
