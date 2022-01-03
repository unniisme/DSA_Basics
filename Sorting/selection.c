#include <stdio.h>

//Function to find the largest element and interchange it with the last element in the list
void Select(int n, long *ar)
{
    long max=ar[0], max_i = 0;

    for (int i=0; i<n; i++)
    {
        if (max < ar[i])
        {
            max = ar[i];
            max_i = i;
        }
    }
    
    ar[max_i] = ar[n-1];
    ar[n-1] = max;
    return;
}

//recursive function to repeate the above function on a section of the list that progressively gets smaller
void SelectionSort(int n, long *ar)
{
    if(n==1){return;}
    Select(n, ar);
    return SelectionSort(n-1, ar);
}

int main()
{
    //Take input, sort the array and output the sorted array
    int n;
    scanf("%d", &n);

    long ar[n];
    for (int i=0; i<n; i++)
    {
        scanf("\n%ld", ar+i);
    }

    SelectionSort(n, ar);

    for (int i=0; i<n; i++)
    {
        printf("%ld\n", ar[i]);
    }

    return 0;
}