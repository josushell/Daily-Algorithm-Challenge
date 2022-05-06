class BSTIterator {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    void fillPQ(TreeNode *root) {
        if (root == NULL)
            return;
        fillPQ(root->left);
        pq.push(root->val);
        fillPQ(root->right);
    }
    BSTIterator(TreeNode* root) {
        fillPQ(root);
    }
    
    int next() {
        int temp = pq.top();
        pq.pop();
        return temp;
    }
    
    bool hasNext() {
        return !pq.empty();
    }
};
