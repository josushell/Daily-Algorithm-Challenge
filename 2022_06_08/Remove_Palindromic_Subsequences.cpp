class Solution {
public:
    bool isPalindrome(string s)
    {
        for(int i = 0;i < s.size() / 2;i++)
        {
            if (s[i] != s[s.size() - 1 - i])
                return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(isPalindrome(s))
            return 1;
        else
            return 2;
        
    }
};

// a, b로만 구성되어있는 문자열이므로 subsequence가 palindrome인 경우는 무조건 2이다.
//예를 들면 -> "ababababa" == "aaaaa" , "bbbb" 두 개의 palindrome subsequence가 생기기 때문
// 예외 사항: 문자열 전체가 palindrome인 경우는 return이 1이므로 따로 체크한다.
