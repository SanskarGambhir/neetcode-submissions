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
        queue<TreeNode*> nodes;

        if(root==nullptr){
            return {};
        }

        TreeNode* temp = root;
        nodes.push(temp);

        while(!nodes.empty()){
            temp = nodes.front();
            nodes.pop();

            TreeNode* tempSwap = temp->left;
            temp->left = temp->right;
            temp->right = tempSwap;

            if(temp->left!=nullptr){
                nodes.push(temp->left);
            }
            if(temp->right!=nullptr){
                nodes.push(temp->right);
            }
        }

        return root;
    }
};
