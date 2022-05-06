#include <map>
using namespace std;

class Solution {
public:
    static bool compare(pair<int, int>a, pair<int, int>b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> m;
        vector<int> result;
        int index = 0;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0;i < nums.size();i++)
        {
            if (nums.size() == 1)
                m.push_back({nums[i], 1});
            
            else if (i == nums.size() - 1)
            {
                if (nums[i] != nums[i - 1])
                    m.push_back({nums[i], 1});
            }
            else
            {
                index = 0;
                while(i < nums.size() - 1 && nums[i] == nums[i + 1])
                {
                    i++;
                    index++;
                }
                m.push_back({nums[i], index + 1});
            }
        }
        sort(m.begin(), m.end(), compare);
        auto iter = m.begin();
        for(int i = 0;i < k;i++)
        {
            result.push_back(iter->first);
            iter++;
        }
        return result;
    }
};

