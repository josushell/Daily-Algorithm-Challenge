class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int result = 0;
        int start = 0;
        int end = nums.size() - 1;
        
        while (start < end && nums[start] < k)
        {
            if (nums[start] + nums[end] < k)
                start++;
            else if (nums[start] + nums[end] > k)
                end--;
            else
            {
                start++;
                end--;
                result++;
            }
        }
        return result;
    }
};


