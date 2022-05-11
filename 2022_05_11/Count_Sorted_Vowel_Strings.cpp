class Solution {
public:
    int DFS(int n, int i, vector<vector<int>> &v)
    {
		// 숫자 count가 다 되면 생성된 것으로 보고 종료
        if (n == 0)
            return 1;
        
		// 범위가 aeiou 범위를 벗어나면 생성 안된것으로 보고 종료
        if (i >= 5)
            return 0;
        
		// 이미 구했던 것이라면 가져옴 -> dynamic programming (메모이제이션)
        if (v[n][i] != -1)
            return v[n][i];
        
		// i를 포함할 때
        int in = DFS(n - 1, i, v);
		// i를 포함하지 않을 때
        int notin = DFS(n, i + 1, v);
        
		// 두 경우로 생성되는 모든 경우의 수를 더해서 저장
        return v[n][i] = in + notin;
    }
    
    int countVowelStrings(int n) {
        vector<vector<int>> v(n + 1, vector<int>(5, -1));
        
        int result = DFS(n, 0, v);
        
        return result;
    }
};
