#include <stdio.h>

void MergeFile(FILE *f1, FILE *f2, FILE *f3, int mult)
{

    fseek(f2, mult*sizeof(int), SEEK_SET);

    int x1, x2;

    while(1)
    {
        int bool1 = fread(&x1, sizeof(int), 1, f1);
        int bool2 = fread(&x2, sizeof(int), 1, f2);

        if(!(bool1 && bool2))
        {
            break;
        }

        if (x1>x2)
        {
            fwrite(&x2, sizeof(int), 1, f3);
            for (int i=0; i<mult-1; i++)
            {
                fread(&x2, sizeof(int), 1, f2);
                fwrite(&x2, sizeof(int), 1, f3);
            }
            fseek(f2, mult*sizeof(int), SEEK_CUR);

            fwrite(&x1, sizeof(int), 1, f3);
            for (int i=0; i<mult-1; i++)
            {
                fread(&x1, sizeof(int), 1, f1);
                fwrite(&x1, sizeof(int), 1, f3);
            }
            fseek(f1, mult*sizeof(int), SEEK_CUR);

        }
        else
        {
            fwrite(&x1, sizeof(int), 1, f3);
            for (int i=0; i<mult-1; i++)
            {
                fread(&x1, sizeof(int), 1, f1);
                fwrite(&x1, sizeof(int), 1, f3);
            }
            fseek(f1, mult*sizeof(int), SEEK_CUR);

            fwrite(&x2, sizeof(int), 1, f3);
            for (int i=0; i<mult-1; i++)
            {
                fread(&x2, sizeof(int), 1, f2);
                fwrite(&x2, sizeof(int), 1, f3);
            }
            fseek(f2, mult*sizeof(int), SEEK_CUR);
        } 

    }

    if(mult*2 > 2)
    {
        return; 
    }

    fclose(f2);

    fseek(f1, 0, SEEK_SET);
    fseek(f3, 0, SEEK_SET);

    while(fread(&x1, sizeof(int), 1, f3))
    {
        fwrite(&x1, sizeof(int), 1, f1);
    }

    fclose(f1);fclose(f3);

    f1 = fopen("input1.txt", "r+");
    f2 = fopen("input1.txt", "r");

    f3 = fopen("temp1.txt", "w+");

    MergeFile(f1, f2, f3, mult*2);

}

int main()
{
    FILE *f1, *f2, *f3;

    f1 = fopen("input1.txt", "r+");
    f2 = fopen("input1.txt", "r");

    f3 = fopen("temp1.txt", "w+");

    fseek(f1, 0, SEEK_END);
    int len = ftell(f1);
    fseek(f1, 0, SEEK_SET);

    

    MergeFile(f1,f2, f3, 1);

    fclose(f1);
    fclose(f2);
    fclose(f3);


}