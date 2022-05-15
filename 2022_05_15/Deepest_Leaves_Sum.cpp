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
    int sum = 0;
    int Deep = 0;
public:
    int GetDeepest(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        
        int leftH = GetDeepest(root->left);
        int rightH = GetDeepest(root->right);
        
        if (leftH > rightH)
            return leftH + 1;
        else
            return rightH + 1;
    }
    
    void DFS(TreeNode *root, int deep)
    {
        if (root == NULL)
            return;
        
        if (deep == Deep - 1)
            sum += root->val;
        
        DFS(root->left, deep + 1);
        DFS(root->right, deep + 1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        Deep = GetDeepest(root);
        DFS(root, 0);
        return sum;
    }
};


