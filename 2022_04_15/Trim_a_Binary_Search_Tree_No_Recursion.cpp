struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while (root != NULL && !(root->val >= low && root->val <= high)) {
            if (root->val < low)
                root = root->right;
            else
                root = root->left;
        }

        if (root == NULL)
            return NULL;

        TreeNode *temp = root;

        while (temp->left != NULL) {
            if (temp->left->val < low)
                temp->left = temp->left->right;
            else
                temp = temp->left;
        }

        temp = root;
        while (temp->right != NULL) {
            if (temp->right->val > high)
                temp->right = temp->right->left;
            else
                temp = temp->right;
        }

        return root;
    }
};


