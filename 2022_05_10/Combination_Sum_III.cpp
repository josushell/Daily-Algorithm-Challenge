class Solution {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        makeCombination(k, n, temp, 1);
        
        return result;
    }
    
    int getSum(vector<int> v)
    {
        int result = 0;
        for(int i = 0;i < v.size();i++)
            result += v[i];
        return result;
    }
    
    void makeCombination(int k, int n, vector<int> &combination, int num)
    {
        if (k == 0)
        {
            if (getSum(combination) == n)
                result.push_back(combination);
            return;
        }
        
        if (num > 9)
            return;
        
        else
        {
            // 넣는 경우
            combination.push_back(num);
            makeCombination(k - 1, n, combination, num + 1);
            
            // 넣지 않는 경우
            combination.pop_back();
            makeCombination(k, n, combination, num + 1);
        }
    }
};


