#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int first, int mid, int last)
{
    int i = first, j = mid + 1;
    int k = 0;
    int *temp = malloc((last - first + 1) * sizeof(int));
    while (i <= mid && j <= last)
    {
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = array[j];
            j++;
            k++;
        }
    }
    if (i > mid)
    {
        while (j <= last)
        {
            temp[k] = array[j];
            j++;
            k++;
        }
    }
    else if (j > last)
    {
        while (i <= mid)
        {
            temp[k] = array[i];
            i++;
            k++;
        }
    }
    j = 0;
    for (int i = first; i <= last; i++)
    {
        array[i] = temp[j];
        j++;
    }

    free(temp);
}

void mergesort(int *array, int first, int last)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2;
        mergesort(array, first, mid);
        mergesort(array, mid + 1, last);
        merge(array, first, mid, last);
    }
}

int main()
{
    FILE *p = fopen("input1.txt", "r");

    int array[500000];

    int i = 0, n = 0;
    while ((fscanf(p, "%d", &array[i]) == 1))
    {
        n++;
        i++;
    }

    fclose(p);


    mergesort(array, 0, n - 1);


    FILE *p2 = fopen("input1.txt", "w+");
    for (int i = 0; i < n; i++)
    {
        fprintf(p2, "%d ", array[i]);
    }
    fclose(p2);
}

