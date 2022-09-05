// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };

// Using BFS

class Solution {
    int len = 0;
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == NULL) {
            vector<vector<int>> result;
            return result;
        }
        
        getHeight(root, 1);

        vector<vector<int>> result(len);
        int index = 0;
        pushItem(result, index, root);
        
        return result;
    }
    
    void pushItem(vector<vector<int>> &result, int idx, Node* root) {
        result[idx].push_back(root->val);

        for(auto child: root->children) {
            pushItem(result, idx + 1, child);
        }
    }
    
    void getHeight(Node *root, int height) {
        len = max(len, height);
        
        for(auto child: root->children) {
            getHeight(child, height + 1);
        }
    }
};
