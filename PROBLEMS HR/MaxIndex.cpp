//Given an array A[] of N positive integers. 
//The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].

// N = 9 
// A[] = {34, 8, 10, 3, 2, 80, 30, 33, 1} 
//Output : 6

int maxIndexDiff(int a[], int n)
{
    // if a[] = [7 3 1 8 9 10 4 5 6]

    // maxL[] = [10 10 10 10 10 10 6 6 6]
    // minR[] = [7 3 1 1 1 1 1 1 1 ]

    int minL[n];
    int maxR[n];

    minL[0] = a[0];
    maxR[n - 1] = a[n - 1];

    for (int i = 1; i < n; i++)
    {
        minL[i] = min(minL[i - 1], a[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        maxR[i] = max(maxR[i + 1], a[i]);
    }

    int i = 0, j = 0;
    int diff = -1;

    while (i < n && j < n)
    {

        if (minL[i] <= maxR[j])
        {
            diff = max(diff, j - i);
            j++;
        }
        else
        {
            i++;
        }
    }

    return diff;
}