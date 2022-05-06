struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
private:
    int offset = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root)
            return root;
        
        convertBST(root->right);
        root->val += offset;
        offset = root->val;
        convertBST(root->left);

        return root;
    }
};
