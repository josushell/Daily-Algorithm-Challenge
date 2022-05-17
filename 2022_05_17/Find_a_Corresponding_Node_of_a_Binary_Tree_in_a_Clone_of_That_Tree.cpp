/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// DFS 이용
class Solution {
private:
    TreeNode *node;
public:
    void getAnswer(TreeNode *cloned, TreeNode *target)
    {
        if (cloned == NULL)
            return;
        
        if (cloned->val == target->val)
        {
            node = cloned;
            return;
        }
        getAnswer(cloned->left, target);
        getAnswer(cloned->right, target);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        getAnswer(cloned, target);
        return node;
    }
};


