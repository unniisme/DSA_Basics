#include <stdio.h>

//A simple function to interchange 2 elements in a list
void Interchange(int *ar, int i, int j)
{
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;

    return;
}

//The function to partition a list around a pivot at a given index
int PivotPartition(int *ar, int left, int right)
{
    int pivot = ar[right];
    int rank = 0;
    for (int i=left; i<=right; i++)
    {
        if (ar[i] < pivot)
        {
            Interchange(ar, left+rank, i);
            rank++;
        }
    }

    Interchange(ar, right, left+rank);

    return left + rank;
}

//The recurcive function to quicksort a list
void QuickSort(int *ar, int left, int right)
{
    while (left < right)
    {
        int mid = PivotPartition(ar, left, right);

        QuickSort(ar, left, mid-1);

        left = mid+1;        
    }
    return;
}

int main()
{
    int n, *ar;

    scanf("%d", &n);

    for (int i=0; i<n; i++)
    {
        scanf("\n%d", ar+i);
    }

    QuickSort(ar, 0, n-1);

    for (int i=0; i<n; i++)
    {
        printf("%d\n", ar[i]);
    }

    return 0;
}