#include <queue>
#include <vector>

using namespace std;

// 우선순위 큐 사용
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int a, b;
        priority_queue<int> queue;
        
        for(int i = 0;i < stones.size();i++)
            queue.push(stones[i]);
        
        while (queue.size() > 1)
        {
            a = queue.top();
            queue.pop();
            
            b = queue.top();
            queue.pop();

            if (a != b)
                queue.push(a - b);
        }
        if (queue.empty() == true)
            return 0;
        else
            return queue.top();
    }
};

