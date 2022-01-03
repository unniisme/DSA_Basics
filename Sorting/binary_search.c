#include <stdio.h>

int recursionCount = 0;

int BinarySearch(int *ar, int i, int j, int target)
{
    recursionCount++;

    int mid = (i + j)/2;

    if(ar[mid] == target)
    {
        return mid;
    }

    else if(ar[i] == ar[j])
    {
        return -1;
    }

    else if((target < ar[i]) || (target > ar[j]))
    {
        return -1;
    }
    
    else
    {

        if (target > ar[mid])
        {
            return BinarySearch(ar, mid+1, j, target);
        }
        else
        {
            return BinarySearch(ar, i, mid, target);
        }
    }
        
}


int main()
{
    int n;

    scanf("%d", &n);

    int ar[n];

    for (int i=0; i<n; i++)
    {
        scanf("\n%d", ar+i);
    }

    int target;

    scanf("\n%d", &target);

    printf("%d\n%d\n", recursionCount, BinarySearch(ar, 0, n-1, target));

    return 0;
}