#include <stdio.h>

int main()
{
    FILE *fp;

    char c[100];

    int i;

    while(1)
    {
        while(1)
        {
            scanf("%s", c);
            if(fp = fopen(c, "r"))
            {
                printf("k cool\n");
                break;
            }
            printf("nope\n");
        }

        int count = 0;

        while(fread(&i, sizeof(int), 1, fp))
        {
            count++;
        }

        printf("Count: %d\n\n", count);

        fseek(fp, 0, SEEK_SET);

        count = 0;

        while((count<100) && (fread(&i, sizeof(int), 1, fp)))
        {
            count++;
            printf("%d ", i);
        }

        printf("\n\n");
    }
    
}