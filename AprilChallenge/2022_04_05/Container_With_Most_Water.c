int min(int a, int b)
{
    return a < b ? a : b;
}

int maxArea(int* height, int heightSize){
    int max = 0;
    int start = 0;
    int end = heightSize - 1;
    int temp;
    
    while (start < end)
    {
        temp = (end - start) * min(height[end], height[start]);
        if (temp > max)
            max = temp;
        if (height[end] > height[start])
            start++;
        else
            end--;
    }

    return max;
}
