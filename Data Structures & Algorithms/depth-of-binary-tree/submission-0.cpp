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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> nodes;
        int depth = 0;

        if(root==nullptr){
            return 0;
        }

        TreeNode* temp = root;
        nodes.push(temp);

        while(!nodes.empty()){
            int size = nodes.size();

            for(int i=0; i<size; i++){
                temp = nodes.front();
                nodes.pop();
                
                if(temp->left!=nullptr){
                    nodes.push(temp->left);
                }
                if(temp->right!=nullptr){
                    nodes.push(temp->right);
                }
            }
            depth += 1;
        }

        return depth;
    }
};
