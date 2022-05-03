class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int end = -1;
        int max = nums[0];
        
        for(int i = 0;i < nums.size();i++)
        {
            if (max > nums[i])
                end = i;
            else
                max = nums[i];
        }
        
        int start = 0;
        int min = nums[nums.size() - 1];
        for(int i = nums.size() - 1;i >= 0;i--)
        {
            if (min < nums[i])
                start = i;
            else
                min = nums[i];
        }
        
        return end - start + 1;
    }
};
