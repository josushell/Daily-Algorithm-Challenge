void swapping(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void nextPermutation(int* nums, int numsSize){
    int i;
    for(i = numsSize - 1;i > 0;i--)
    {
        if (nums[i] > nums[i - 1])
            break;
    }
    
    if (i <= 0)
    {
        for(int k = numsSize - 1;k > 0;k--)
        {
            for(int j = 0;j < k;j++)
            {
                if (nums[j] > nums[j + 1])
                    swapping(&nums[j], &nums[j + 1]);
            }
        }
        return;
    }
    
    for(int j = numsSize - 1;j >= 0;j--)
    {
        if (nums[i - 1] < nums[j])
        {
            swapping(&nums[i - 1], &nums[j]);
            for(int k = numsSize - 1;k > i;k--)
            {
                for(int j = i;j < k;j++)
                {
                    if (nums[j] > nums[j + 1])
                        swapping(&nums[j], &nums[j + 1]);
                }
            }
            return;
        }
    }
 
}


