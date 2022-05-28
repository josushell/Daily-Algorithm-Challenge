// Time: O(N), Space: O(1) 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for(int i = 0;i <= nums.size();i++)
        {
            if (nums[i] != i)
            {
                return i;
            }
        }
        return nums.size();
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;

        for(int i = 0;i < nums.size();i++)
            sum += nums[i];

        int total = (nums.size() * (nums.size() + 1)) / 2;

        return total - sum;
    }
};
