class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* tempSwap = root->left;
        root->left = root->right;
        root->right = tempSwap;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};