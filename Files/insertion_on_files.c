//Program to implement insertion sort for numbers in a file
#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insert(int *array, int marker)
{
    for (int i = marker - 1; i >= 0; i--)
    {
        if (array[marker] <= array[i])
        {
            swap(&array[marker], &array[i]);
            marker--;
        }
        else
        {
            break;
        }
    }
}

void insertionSort(int *array, int n)
{
    if (n == 1)
    {
        insert(array, 0);
    }
    else
    {
        insertionSort(array, n - 1);
        insert(array, n - 1);
    }
}

int main()
{
    FILE *p = fopen("input2.txt", "r");

    int array[500000];

    int i = 0, n = 0;
    while ((fscanf(p, "%d", &array[i]) == 1))
    {
        n++;
        i++;
    }

    fclose(p);


    insertionSort(array, n);


    FILE *p2 = fopen("input2.txt", "w+");
    for (int i = 0; i < n; i++)
    {
        fprintf(p2, "%d ", array[i]);
    }
    fclose(p2);
}


