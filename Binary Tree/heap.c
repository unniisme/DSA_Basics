#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

//Functions to navigate to Parent, Left and Right elements of a node
int Parent(int i)
{
    return (i-1)/2;
}
int Left(int i)
{
    return 2*i+1;
}
int Right(int i)
{
    return 2*i+2;
}

int H_size = 0;

//A shorthand function to exchange 2 nodes
void Exchange(int* H, int i, int j)
{
    int temp = H[i];
    H[i] = H[j];
    H[j] = temp;
    return;
}

//The sift up function
//Compares target with its parent, replaces their values if the parent is larger than the target.
//Then calls iteself recursively on the parent.
void SiftUp(int* H, int target)
{
    if(target==0)
    {
        return;
    }

    //If target of siftup is greater than its parent, exchange it with the parent and sift up the parent.
    if(H[target] < H[Parent(target)])
    {
        Exchange(H, target, Parent(target));
        return SiftUp(H, Parent(target));
    }

    return;
}

//The Min Heapify function
//Compares the target element with both it's children to find the smallest one.
//If one of the children is smaller than the target, exchange the child with itself and call itself recurcively on the child.
void MinHeapify(int* H, int pos)
{
    //If the node has no subtrees, return
   if (Left(pos) >= H_size)
   {
       return;
   }

    //Proceedure to find the lowest element among the node and its 2 children
   int min = pos;

   if (H[Left(pos)] <  H[pos])
   {
       min = Left(pos);
   }

   if (Right(pos)<H_size && H[Right(pos)] < H[min])
   {
       min = Right(pos);
   }

    //If the node is the smallest, the it is already heap.
   if (pos == min)
   {
       return;
   }

    //Exchange the node and whichever subtree has the lowest value, call minheap on the exchanged subtree
   Exchange(H, pos, min);
   return MinHeapify(H, min);

}

//Function to insert an element into the heap
void Insert(int* H, int add)
{
    if(H_size >= MAX_SIZE)
    {
        return;
    }

    H[H_size] = add;
    H_size++;
    SiftUp(H, H_size-1);
    return;
}

//The DecreaseKey function
//Decreases the value in a key and sift it up to maintain a heap
int DecreaseKey(int* H, int i, int value)
{
    //If the value is increased or if the key is outside the heap, return error.
    if (i >= H_size || value > H[i])
    {
        return 1;
    }
    //Change the value of the key and then sift up
    H[i] = value;
    SiftUp(H, i);
    return 0;
}

//Function to print heap in array order
void PrintHeap(int* H)
{
    for (int i=0; i<H_size; i++)
    {
        printf("%d\n", H[i]);
    }
    return;
}

//The BuildHeap Function
void BuildHeap(int* H, int n)
{ 
    if(n<0)
    {
        return;
    }
    //Do min Heapify for all keys from n to 0
    //Note that I will be inputting n = H_size/2 outside the function
    MinHeapify(H, n);
    return BuildHeap(H, n-1);
}

//Function to delete node
//Note that this is just extractMin on a subtree
int Delete(int* H, int i)
{
    //If index out of bound, return error
    if (i >= H_size)
    {
        return -1;
    }

    //Decrease the size of the heap
    H_size--;

    //Replace the element to be deleted with the final element in the heap
    //Call Minheapify on the replaced element so that it becomes a heap
    int min = H[i];
    H[i] = H[H_size];
    MinHeapify(H, i);
    return min;
}

//Wrap function for Deleting
void DeleteIndex(int* H, int i)
{
    int delete = Delete(H, i);
    if (delete == -1)
    {
        printf("Operation Fail\n");
    }
    return;
}

//Extract min is Delete applied on the root.
int ExtractMin(int* H)
{
    return Delete(H, 0);
}

//Returns the root of the heap which is the smallest element in the heap
int FindMin(int* H)
{
    if (H_size == 0)
    {
        return;
    }
    return H[0];
}

//Wrapfunction for ExtractMin
void PrintExtractMin(int* H)
{
    printf("%d\n", ExtractMin(H));
}

int main()
{
    int H[MAX_SIZE];

    int n=0;
    scanf("%d", &n);
    H_size = n;

    for (int i=0; i<n; i++)
    {
        scanf("%d", H+i);
    }

    BuildHeap(H, (n-1)/2);

    int input, input1;
    while(1)
    {
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                scanf("%d", &input);
                Insert(H, input);
                break;
            case 2:
                scanf("%d",&input);
                DeleteIndex(H, input);
                break;
            case 3:
                PrintExtractMin(H);
                break;
            case 4:
                PrintHeap(H);
                break;
            case 5:
                scanf("%d",&input);
                scanf("%d",&input1);
                if(DecreaseKey(H, input, input1))
                {
                    printf("Operation Fail\n");
                }
                break;
            case 6:
                printf("%d\n", FindMin(H));
                break;
            default:
                exit(0);                
        }        
    }

    return 0;
}
