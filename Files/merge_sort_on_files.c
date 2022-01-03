#include<stdio.h>
#include<stdlib.h>
int merge(FILE *p1, FILE *p2, FILE *p3,long ls) 	//fn to merge two lists
{
    int i=0,j=0;                                	//indices i and j to count the list length
    int x1,x2;   
    int b1,b2;                              		//x1 and x2 to read the elements into
 
    b1= fread(&x1,sizeof(int),1,p1);
            
  	b2= fread(&x2,sizeof(int),1,p2);
            
    while(i<ls&&j<ls)
    {
    	if(!b1||!b2)
    	{
    		break;
    	}
        if(x1<x2)                               	//writing the smaller element into the temporary file
        {
            fwrite(&x1,sizeof(int),1,p3);
            printf("%d ", x1);
            i++;
            if(i<ls)
            {
                 b1=fread(&x1,sizeof(int),1,p1);
            }
        }
        else
        {
            fwrite(&x2,sizeof(int),1,p3);
            printf("%d ", x2);
            j++;
            if(j<ls)
            {
                 b2=fread(&x2,sizeof(int),1,p2);
            }
        }
    }
    while(i<ls&&b1)                         	        //if either lists get over ,write the rest of the elements 
    {
        fwrite(&x1,sizeof(int),1,p3);
        printf("%d ", x1);
        i++;
        if(i<ls)
        {
              b1=fread(&x1,sizeof(int),1,p1);
        }
    }
    while(j<ls&&b2)
    {
        fwrite(&x2,sizeof(int),1,p3);
        printf("%d ", x2);
        j++;
        if(j<ls)
        {
                b2=fread(&x2,sizeof(int),1,p2);
        }
    }
    return b1&&b2;
}

void mergesort(FILE *p1, FILE *p2, FILE *p3,long ls,long s)
{
    int c;
    fseek(p2,ls*sizeof(int),SEEK_SET);          	//pointer 2 is kept at the start of the second list
    while(1)
    {
    	c=merge(p1,p2,p3,ls);
        printf("\t");
    	if(!c)
    		break;
        fseek(p1, ls*sizeof(int), SEEK_CUR);    	//updating the position of p1 and p2 to the start of next lists
        fseek(p2, ls*sizeof(int), SEEK_CUR);    
    }
    printf("\n");
    fclose(p1);
    fclose(p2);
    fclose(p3);
    p1=fopen("input1.txt","w");
    p3=fopen("temp1.txt","r");
   

    int d,status;                                    //variable to read from file into
   
    while(1)             			    	//reading from temp.txt back to input1.txt
    {
        status=fread(&d,sizeof(int),1,p3);
        if(!status)
        	break;
        fwrite(&d,sizeof(int),1,p1);
    }

    if(ls>s)                                        //if the list length is greater than the file length
    {
        return; 
    }
    fclose(p1);
    fclose(p3);

    p1 = fopen("input1.txt", "r");
    p2 = fopen("input1.txt", "r");
    p3 = fopen("temp1.txt", "w");

    mergesort(p1,p2,p3,ls*2,s);
    
}


int main()
{
    FILE *p1, *p2, *p3;
    p1=fopen("input1.txt","r");            //pointers to read and write from input file
    p2=fopen("input1.txt","r");           

    p3=fopen("temp1.txt","w");              //pointer to write and read in a temporary file
  
    fseek(p1,0,SEEK_END);                   //placing pointer at the end of the file
    long size = ftell(p1)/sizeof(int);      //finding the current position position of the pointer ie size of the file and dividing it by sizeof int to find the length of the array
    fseek(p1,0,SEEK_SET);                   //placing the pointer back at the start of the file
    long list_size=1;                       //size of list
    mergesort(p1,p2,p3,list_size,size);     //calling mergesort fn with list size 1
    int x;
    int status=0;
    while(fread(&x,sizeof(int),1,p1))
    {
        printf("%d ",x);
    }
    return 0; 
 
}
