class Solution {
public:
    void rearrange(TreeNode *root, TreeNode *&result) {
        if (root == NULL)
            return;
        rearrange(root->left, result);
        TreeNode *temp = new TreeNode(root->val);
        result->right = temp;
        result = result->right;
        rearrange(root->right, result);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *temp = new TreeNode(0, NULL, NULL);
        TreeNode *result = temp;
        rearrange(root, temp);
        return result->right;
    }
};
