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

// Solution: Post-Order tree traversal & recursion

class Solution {
public:
   TreeNode* pruneTree(TreeNode* root) {
       if (root == NULL) {
           return root;
       }
   
       root->left = pruneTree(root->left);
       root->right = pruneTree(root->right);
       // if left and right is null and root->val is zero, then remove subtree
	   if (root->val == 0 && root->left == NULL && root->right == NULL) {
           return NULL;
       }
       
       return root;
   }
};


