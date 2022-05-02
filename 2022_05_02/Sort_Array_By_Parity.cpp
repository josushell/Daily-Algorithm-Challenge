// 첫번째 버전
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;
        
        for(int i = 0; i < nums.size();i++)
        {
            if (nums[i] % 2 == 0)
                result.insert(result.begin(), nums[i]);
            else
                result.push_back(nums[i]);
        }
        return result;
    }
};

// 2 pointer를 활용한 두번째 버전
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
  
        while(start < end)
        {
            if (nums[start] % 2 != 0 && nums[end] % 2 == 0)
            {
                swap(nums[start++], nums[end--]);
                continue;
            }
            
            if (nums[start] % 2 == 0)
                start++;
            
            else if (nums[end] % 2 != 0)
                end--;
        }
        
        return nums;
    }
};
