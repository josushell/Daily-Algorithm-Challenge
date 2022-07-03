// Greedy

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int inc = 1, dec = 1;
        
        for(int i = 0;i < nums.size() - 1;i++)
        {
            if (nums[i] < nums[i + 1]) // 증가
                inc = dec + 1;
            else if (nums[i] > nums[i + 1]) // 감소
                dec = inc + 1;
        }
        
        return max(inc, dec);
    }
};


