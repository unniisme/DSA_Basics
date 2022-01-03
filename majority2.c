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

    int f = 0;
    int curr = 0;

    for (int i = 0; i<n; i++)
    {
        if(f==0)
        {
            f++;
            curr = ar[i];
        }

        else if(ar[i] == curr)
        {
            f++;
        }

        else
        {
            f--;
        }
    }

    f = 0;
    for(int i = 0; i<n; i++)
    {
        if(ar[i] == curr)
        {
            f++;
        }
    }

    if (!(f > n/2))
    {
        printf("No Majority\n");
    }

    else
    {
        printf("%d\n", curr);
    }

    return 0;
}