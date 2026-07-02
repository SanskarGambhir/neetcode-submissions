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
    int preorderKaIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = buildTreeFunction(preorder, inorder);
        return root;
    }

    TreeNode* buildTreeFunction(vector<int>& preorder, vector<int>& inorder){
        int n = inorder.size();
        int rootKaIndex = 0;
        vector<int> leftSubtree;
        vector<int> rightSubtree;

        if(inorder.size()==0){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preorderKaIndex]);

        for(int i=0; i<n; i++){
            if(inorder[i] == preorder[preorderKaIndex]){
                rootKaIndex = i;
                break;
            }
            leftSubtree.push_back(inorder[i]);
        }
        preorderKaIndex++;

        for(int i=rootKaIndex+1; i<n; i++){
            rightSubtree.push_back(inorder[i]);
        }

        root->left = buildTreeFunction(preorder, leftSubtree);
        root->right = buildTreeFunction(preorder, rightSubtree);

        return root;
    }
};
