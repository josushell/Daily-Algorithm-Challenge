// Sliding Window
// with using set

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int leftIndex = 0;
        int maxSum = 0;
        
        unordered_set<int> s;
        int tempsum = 0;
        for(int rightIndex = 0;rightIndex < nums.size();rightIndex++)
        {
            tempsum += nums[rightIndex];
            while(leftIndex < rightIndex && s.count(nums[rightIndex]) >= 0)
            {
                s.erase(nums[leftIndex]);
                tempsum -= nums[leftIndex];
                leftIndex++;
            }
            s.insert(nums[rightIndex]);
            maxSum = max(maxSum, tempsum);
        }
        
        return maxSum;
    }
};
