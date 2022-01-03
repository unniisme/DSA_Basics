#include <stdio.h>

//The merging algorithm
void Merge(int *ar, int start, int mid, int end)
{
    int temp[end - start + 1];
    int i = start;
    int j = mid + 1;
    int k = 0;

    //Go through each section of the list, add the smaller element into the temporary array
    while ((i<=mid) && (j<=end) && (k<end - start + 1))
    {
        if(ar[i]>ar[j])
        {
            temp[k] = ar[j];
            j++;
        }
        else
        {
            temp[k] = ar[i];
            i++;
        }
        k++;
    }

    while ((i<=mid) && (k<end - start + 1))
    {
        temp[k] = ar[i];
        i++;
        k++;
    }

    while ((j<=end) && (k<end - start + 1))
    {
        temp[k] = ar[j];
        j++;
        k++;
    }

    //Replace the part of the array with the temporary array
    for (i=0; i<end - start + 1; i++)
    {
        ar[start + i] = temp[i]; 
    }

}

//Recursively call the algorithm on smaller sections of the array, then merge the arrays.
void MergeSort(int *ar, int start, int end)
{
    if (start == end)
    {
        return;
    }

    int mid = (start + end)/2;

    MergeSort(ar, start, mid);
    MergeSort(ar, mid+1, end);

    Merge(ar, start, mid, end);

    return;
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

    MergeSort(ar, 0, n-1);

    for (int i =0; i<n; i++)
    {
        printf("%d\n", ar[i]);
    }

    return 0;
}