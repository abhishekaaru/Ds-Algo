// Merge 2 array without extra space


// Method 1
void merge(int a[], int b[], int n, int m)
{

    int i = 0;

    while (i < n)
    {
        if (a[i] > b[0])
        {

            swap(a[i], b[0]);
            sort(b, b + m);
        }
        i++;
    }
}

// Method 2
void merge(int a[], int b[], int n, int m)
{
    int i = 0, j = 0, k = n - 1;

    // Untill i less than equal to k
    // or j is less tha m
    while (i <= k and j < m)
    {
        if (a[i] < b[j])
            i++;
        else
        {
            swap(b[j++], a[k--]);
        }
    }

    // Sort first array
    sort(a, a + n);

    // Sort second array
    sort(b, b + m);
}

// Method 3
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

void merge(int a[], int b[], int n, int m)
{
    int i, j, gap = n + m;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        for (i = 0; i + gap < n; i++){

            if (a[i] > a[i + gap]){
                swap(a[i], a[i + gap]);
            }
        }

        for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++){

            if (a[i] > b[j]){
                swap(a[i], b[j]);
            }
        }

        if (j < m)
        {

            for (j = 0; j + gap < m; j++){

                if (b[j] > b[j + gap]){
                    swap(b[j], b[j + gap]);
                }
            }
        }
    }
}