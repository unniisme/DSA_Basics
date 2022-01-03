#include <stdio.h>

//Function to insert an element in the right position given a part of an array
void Insertion(int *ar, int i)
{
    int hole = i-1;
    int insert = ar[i];

    //Goes through the array from end to beginning, moving each element foreward if it's larger than the target element. Inserts the target elemnt whenever the next element is smaller than itself
    while (hole >= 0 && ar[hole] >= insert)
    {
        ar[hole+1] = ar[hole];
        hole--;
    }
    ar[hole+1] = insert;
}

//recursive function to perform insertion sorting
void InsertionSort(int *ar, int n)
{
    if(n==1)
    {
        return;
    }

    InsertionSort(ar, n-1);

    Insertion(ar,n-1);
    
    return;
}


int main(){

    int n, *ar;

    scanf("%d", &n);

    for (int i=0; i<n; i++)
    {
        scanf("\n%d", ar+i);
    }

    InsertionSort(ar,n);

    for (int i=0; i<n; i++)
    {
        printf("%d\n", ar[i]);
    }

    return 0;
}