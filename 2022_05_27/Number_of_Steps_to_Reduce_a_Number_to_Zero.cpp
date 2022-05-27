// Number of Steps to Reduce a Number to Zero

class Solution {
public:
    int numberOfSteps(int num) {
        int result = 0;

        while(num > 0)
        {
            result++;
            if (num % 2 == 0)
                num = num / 2;

            else
                num -= 1;

        }
        return result;
    }
};
