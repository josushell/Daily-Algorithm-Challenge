class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int iter: nums)
            sum += iter;
        
        int target = sum - x;
        int result = 0;
        int leftIndex = 0;
        
        int tempSum = 0;
        bool flag = false;
        for(int rightIndex = 0;rightIndex < nums.size();rightIndex++)
        {
            tempSum += nums[rightIndex];
            while(leftIndex < rightIndex && tempSum > target)
            {
                tempSum -= nums[leftIndex];
                leftIndex++;
            }
            
            if (tempSum == target)
            {
                flag = true;
                result = max(result, rightIndex - leftIndex + 1);
            }
        }
        if (flag)
            return result;
        else
            return -1;
    }
};
