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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> nodes;

        if(root == nullptr){
            return {};
        }

        TreeNode* temp = root;
        nodes.push(temp);

        while(!nodes.empty()){
            vector<int> tempVector;
            int size = nodes.size();

            for(int i=0; i<size; i++){
                temp = nodes.front();

                tempVector.push_back(temp->val);
                nodes.pop();

                if(temp->left!=nullptr){
                    nodes.push(temp->left);
                }
                if(temp->right!=nullptr){
                    nodes.push(temp->right);
                }           
            }

            result.push_back(tempVector);
        }

        return result;
    }
};
