bool checkValid(char *s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

bool validPalindrome(char *s){
    int start = 0;
    int end = 0;
    while (s[end] != 0)
        end++;
    
    end--;
    while (start < end)
    {
        if (s[start] == s[end])
        {
            start++;
            end--;
        }
        else
        {
            return checkValid(s, start + 1, end) || checkValid(s, start, end - 1);
        }
    }
    return true;

}

