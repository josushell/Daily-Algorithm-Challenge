int countInArr(int *arr, int size, int n)
{
    int num = 0;
    for(int i = 0;i < size;i++)
    {
        if (arr[i] == n)
            num++;
    }
    return num;
}

int threeSumMulti(int* arr, int arrSize, int target){
    long sum = 0;
    long a, b, c;
    
    for(int i = 0;i <= target;i++)
    {
        for(int j = i;j <= target;j++)
        {
            for(int k = j;k <= target;k++)
            {
                if (i + j + k == target)
                {
                    a = countInArr(arr, arrSize, i);
                    b = countInArr(arr, arrSize, j);
                    c = countInArr(arr, arrSize, k);

                    if (a != 0 && b != 0 && c != 0)
                    {
                        if (i != j && i != k && j != k)
                            sum += a * b * c;
                        else if (i == j && j == k)
                            sum += (a * (a - 1) * (a - 2)) / 6;

                        else if (i == j)
                            sum += ((a * (a - 1)) / 2) * c;
 
                        else if (i == k)
                            sum += ((a * (a - 1)) / 2) * b;

                            else if (j == k)
                            sum += ((b * (b - 1)) / 2) * a;

                        sum = sum % 1000000007;
                    }
                }
            }
        }
    }
    return (int)sum;
}
