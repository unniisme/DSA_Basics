#include <stdio.h>

//A simple function to exchange the value of 2 elements in an array
void exchange(int *ar, int i, int j)
{
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}


int main()
{
    //declare and take input for n, k and the array
    int n;
    scanf("%d", &n);

    int ar[n];

    for (int i = 0; i<n; i++)
    {
        scanf("%d", ar+i);
    }

    int k;
    scanf("%d", &k);

    int pivot = ar[k];

    int r = 0;
    for (int i = 0; i<n; i++)
    {
        if (ar[i] < pivot)
        {
            r++;
        }
    }

    //bring the pivot element to it's highest place as first ocurrance
    exchange(ar, r, k);

    //the algorithm
    int i=0;
    int j=r;
    while ((i<r) && (j<n))
    {
        if(ar[i]<pivot)
        {
            i++;
        }

        if(ar[j]<pivot)
        {
            exchange(ar, i, j);
        }
        j++;
    }

    for (int i = 0; i<n; i++)
    {
        printf("%d\n", ar[i]);
    }

    return 0;

}