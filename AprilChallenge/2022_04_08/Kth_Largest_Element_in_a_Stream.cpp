#include <queue>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int index;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i = 0;i < nums.size();i++)
        {
            pq.push(nums[i]);
            if (pq.size() > k)
                pq.pop();
        }
        index = k;
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > index)
            pq.pop();
        return pq.top();
    }
    
};
