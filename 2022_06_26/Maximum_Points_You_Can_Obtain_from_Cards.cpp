// Sliding Window

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for(int iter: cardPoints)
            sum += iter;

        int tempsum = 0;
        for(int i = 0;i < cardPoints.size() - k;i++)
            tempsum += cardPoints[i];

        int leftIndex = 0;
        int result = tempsum;
        for(int rightIndex = cardPoints.size() - k;rightIndex < cardPoints.size();rightIndex++)
        {

            int temp = tempsum + cardPoints[rightIndex] - cardPoints[leftIndex];
            leftIndex++;
            result = min(result, temp);
            tempsum = temp;
        }
        return sum - result;
    }
};
