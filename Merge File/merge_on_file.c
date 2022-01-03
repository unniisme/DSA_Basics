#include <stdio.h>



void MergeFile(FILE *f1, FILE *f2, FILE *f3, int mult)
{

    fseek(f2, mult, SEEK_SET);

    long x1, x2;

    while(!feof(f2))
    {
        fscanf(f1, "%ld ", &x1);
        fscanf(f2, "%ld ", &x2);


        if (x1>x2)
        {
            for (int i=0; i<mult; i++)
            {
                fprintf(f3, "%ld ", x2);
                fscanf(f2, "%ld ", &x2);
            }
            for (int i=0; i<mult; i++)
            {
                fprintf(f3, "%ld ", x1);
                fscanf(f1, "%ld ", &x1);
            }
        }
        else
        {
            for (int i=0; i<mult; i++)
            {
                fprintf(f3, "%ld ", x1);
                fscanf(f1, "%ld ", &x1);
            }
            for (int i=0; i<mult; i++)
            {
                fprintf(f3, "%ld ", x2);
                fscanf(f2, "%ld ", &x2);
            }
        } 

    }

    if(mult*2 > 0)
    {
        return; 
    }

    fclose(f1);fclose(f2);fclose(f3);

    f1 = fopen("temp1.txt", "r");
    f2 = fopen("temp1.txt", "r");
    f3 = fopen("temp1.txt", "w+");

    MergeFile(f1, f2, f3, mult*2);

}

int main()
{
    FILE *f1, *f2, *f3;

    f1 = fopen("input1.txt", "r");
    f2 = fopen("input1.txt", "r");

    f3 = fopen("temp1.txt", "w+");

    fseek(f1, 0, SEEK_END);
    int len = ftell(f1);
    fseek(f1, 0, SEEK_SET);
    

    MergeFile(f1,f2, f3, 2);

    fclose(f1);
    fclose(f2);
    fclose(f3);


}