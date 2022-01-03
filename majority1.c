#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int ar[n];

    for (int i =0; i<n; i++)
    {
        scanf("%d",ar+i);
    }

    int count = 0;
    int max_count = 0;
    int current_num = 0;
    int max_num = 0;

    for (int i = 0; i<n; i++)
    {
        current_num = ar[i];
        count = 0;

        for (int j = 0; j<n; j++)
        {
            if (current_num == ar[j])
            {
                count++;
            }
        }

        if (count > max_count)
        {
            max_count = count;
            max_num = current_num;
        }
    }

    if (max_count > n/2)
    {
        printf("%d\n", max_num);
    }

    else
    {
        printf("No Majority\n");
    }

    return 0;
}