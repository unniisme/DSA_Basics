#include <stdio.h>

//Function to write the inserted array from a section of the full array into the temporary file
void WriteInsert(FILE *f1, FILE *f2, long len, long cutoff)
{
    int target, x;

    fseek(f1, -cutoff*sizeof(int), SEEK_END);
    fread(&target, sizeof(int), 1, f1);

    //The insertion algorithm
    while (fread(&x, sizeof(int), 1, f1))
    {

        if (x<target)
        {
            fwrite(&x, sizeof(int), 1, f2);
        }

        else
        {
            break;
        }

    }

    fwrite(&target, sizeof(int), 1, f2);
    
    return;
}

//Function to write the now sorted sub array into the corresponding place in the input file
void MergeInsert(FILE *f1, FILE *f2, long len, long cutoff)
{
    int x;

    fseek(f1, -cutoff*sizeof(int), SEEK_END);
    fseek(f2, 0, SEEK_SET);

    while (fread(&x, sizeof(int), 1, f2))
    {
        fwrite(&x, sizeof(int), 1, f1);
    }
    return;
}

//A relic of the recursive function
/*
void InsertionFile(FILE *f1, FILE *f2, long len, long cutoff)
{
    if (cutoff>len)
    {
        return;
    }

    WriteInsert(f1, f2, len, cutoff);
    MergeInsert(f1, f2, len, cutoff);

    fflush(f1);
    f2 = fopen("temp2.txt", "w+");

    InsertionFile(f1, f2, len, cutoff + 1);
}
*/

int main()
{

    FILE *f1, *f2;

    f1 = fopen("input2.txt", "r+");

    f2 = fopen("temp2.txt", "w+");

    //Determine the size of the input array
    fseek(f1, 0, SEEK_END);
    long len = ftell(f1)/sizeof(int);
    fseek(f1, 0, SEEK_SET);

    //Non recursive algorithm to perform insertion on subsequently larger arrays
    for(long cutoff = 1; cutoff<=len; cutoff++)
    {
        WriteInsert(f1, f2, len, cutoff);
        MergeInsert(f1, f2, len, cutoff);

        fflush(f1);
        fclose(f2);
        f2 = fopen("temp2.txt", "w+");
    }

    fclose(f1); fclose(f2);

    printf("\nDone!\n");


    return 0;
}
