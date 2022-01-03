#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f1, *f2;

    int stuff[10] = {1,2,2,1,4,7,3,2,6,3}, n;

    f1 = fopen("input1.txt", "w");
    f2 = fopen("input2.txt", "w");

    //scanf("%d",&n);
    n=10;

    for (int i=0; i<n; i++)
    {
        int random = rand()%20;
        fwrite(&random, sizeof(int), 1, f1);
        fwrite(&random, sizeof(int), 1, f2);
    }
    fclose(f1);
    fclose(f2);
}