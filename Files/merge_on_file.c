#include <stdio.h>

//Shorthand to read an integer
int Read(int * p1, FILE *fp)
{
    return (fread(p1, sizeof(int), 1, fp));
}

//Function to merge consecutive pairs of subarrays of given length in the input file and write it into the temporary file
int Merge(FILE *f1, FILE *f2, FILE *f3, int mult)
{

    int i = 0;
    int j = 0;

    int x1,x2;

    int bool1 = Read(&x1, f1);
    int bool2 = Read(&x2, f2);

    //loop runs through the left and right subarrays and writes the smaller element into the temporary file
    while (i<mult && j<mult)
    {

        if(!(bool1&&bool2))
        {
            break;
        }


        if(x1>x2)
            {
                fwrite(&x2, sizeof(int), 1, f3);
                
                j++;

                if(j<mult)
                {
                    bool2 = Read(&x2, f2);
                }
            }
        else
            {
                fwrite(&x1, sizeof(int), 1, f3);
                
                i++;

                if(i<mult)
                {
                    bool1 = Read(&x1, f1);
                }

            } 
    }

    //Writes either if the remaining list if one list encounters EOF or is finished
    while(j<mult && bool2)
    {
        fwrite(&x2, sizeof(int), 1, f3);
                
        j++;

        if(j<mult)
        {
            bool2 = Read(&x2, f2);
        }

    }

    while(i<mult && bool1)
    {
        fwrite(&x1, sizeof(int), 1, f3);
                
        i++;

        if(i<mult)
        {
            bool1 = Read(&x1, f1);
        }
    }

    //Returns EOF status
    return bool1&&bool2;
}

//Recursive function to sort and rewrite the input array
void MergeFile(FILE *f1, FILE *f2, FILE *f3, int mult, long len)
{

    fseek(f2, (mult)*sizeof(int), SEEK_SET);

    int bool = 1;

    //Merge the files in batches until EOF is encountered
    while(bool)
    {
        bool = Merge(f1, f2, f3, mult);
        
        fseek(f1, (mult)*sizeof(int), SEEK_CUR);
        fseek(f2, (mult)*sizeof(int), SEEK_CUR);
    }


    fclose(f2);

    //Seek back at the end of one set of batches and rewrite the input array
    fseek(f1, 0, SEEK_SET);
    fseek(f3, 0, SEEK_SET);

    int x;

    while(fread(&x, sizeof(int), 1, f3))
    {
        fwrite(&x, sizeof(int), 1, f1);
    }

    fclose(f1);fclose(f3);

    //End condition
    if(mult > len)
    {
        return; 
    }

    f1 = fopen("input1.txt", "r+");
    f2 = fopen("input1.txt", "r");

    f3 = fopen("temp1.txt", "w+");


    MergeFile(f1, f2, f3, mult*2, len);

}

int main()
{

    FILE *f1, *f2, *f3;

    f1 = fopen("input1.txt", "r+");
    f2 = fopen("input1.txt", "r");

    f3 = fopen("temp1.txt", "w+");

    //Determine the size of the input array
    fseek(f1, 0, SEEK_END);
    long len = ftell(f1)/sizeof(int);
    fseek(f1, 0, SEEK_SET);


    MergeFile(f1,f2, f3, 1, len);

    printf("Done!\n");

    return 0;
}