/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// BFS 사용
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root;
        
        // queue에 넣기
        queue<Node*> q;
        
        q.push(root);
        q.push(NULL);
        
        // queue 사이즈가 1 이상인 경우에 돌기
        while (q.size() > 1)
        {
            Node *cur = q.front();
            q.pop();
            
            if (cur == NULL)
            {
                q.push(NULL);
                continue;
            }
            // 가장 앞에 있는 요소를 빼서 이전 요소와 연결시킴
            cur->next = q.front();
            if (cur->left != NULL)
                q.push(cur->left);
            
            if (cur->right != NULL)
                q.push(cur->right);
        }
        return root;
    }

};
