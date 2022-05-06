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
private:
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *prev, *temp;
public:
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        temp = prev;
        
        iteration(root);
        swap(first->val, second->val);
        
        delete(temp);
    }
    void iteration(TreeNode *root) {
        if (root == NULL)
            return;
        
        iteration(root->left);
        
        if(first == NULL && root->val < prev->val)
            first = prev;
        if (first != NULL && root->val < prev->val)
            second = root;
        prev = root;
        
        iteration(root->right);
    }
};
