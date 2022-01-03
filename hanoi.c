#include <stdio.h>

//A function to ind the topmost disk index on a tower
int TopDisk(int *t)
{
    int i=0;
    while (t[i]!=0)
    {
        i++;
    }

    return i;
}

//Function to move the topmost disk of a tower onto another
void move(int *t1,int *t2)
{
    t2[TopDisk(t2)] = t1[TopDisk(t1)-1];
    t1[TopDisk(t1)-1] = 0;
}

//Recursive function for solving the tower of hanoi
void doHanoi(int n, int *t0, int *t1, int *t2, int t0_n, int t1_n, int t2_n)
{
    if(n==1)
    {
        printf("Move Disk %d from Pole %d to Pole %d\n", t0[TopDisk(t0)-1], t0_n, t2_n);
        return move(t0,t2);
    }

    doHanoi(n-1, t0, t2, t1, t0_n, t2_n, t1_n);

    printf("Move Disk %d from Pole %d to Pole %d\n", t0[TopDisk(t0)-1], t0_n, t2_n);
    move(t0, t2);

    return doHanoi(n-1, t1, t0, t2, t1_n, t0_n, t2_n);
}


int main()
{
    //Size of tower
    int n;

    scanf("%d", &n);

    //Initializing the towers such that the first tower is stacked and the other 2 towers are empty
    int tower0[n], tower1[n], tower2[n];

    for (int i=0; i<=n; i++)
    {
        tower0[i] = n-i;
        tower1[i] = 0;
        tower2[i] = 0;
    }

    doHanoi(n, tower0, tower1, tower2, 0, 1, 2);

    return 0;

}
