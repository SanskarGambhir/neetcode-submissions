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
        TreeNode* result = riyalBuildTreeFunction(preorder, inorder);
        return result;
    }

    TreeNode* riyalBuildTreeFunction(vector<int>& preorder, vector<int>& inorder){
        vector<int> leftSubArray;
        vector<int> rightSubArray;
        int n = inorder.size();
        int rootKaIndex = 0;

        if(inorder.size()==0){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preorderKaIndex]);

        for (int i=0; i<n; i++) {
            if(inorder[i]==preorder[preorderKaIndex]){
                rootKaIndex = i;
                break;
            }
        }
        preorderKaIndex++;

        for (int i=0; i<rootKaIndex; i++) {
            leftSubArray.push_back(inorder[i]);
        }

        for (int i=rootKaIndex+1; i<n; i++) {
            rightSubArray.push_back(inorder[i]);
        }

        root->left = riyalBuildTreeFunction(preorder, leftSubArray);
        root->right = riyalBuildTreeFunction(preorder, rightSubArray);

        return root;
    }
};
