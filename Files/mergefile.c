#include<stdio.h>
#include<stdlib.h>
int merge(FILE *f1, FILE *f2,FILE *t, int lsize)
{
    int x,y;
    int el1,el2; 
    el1=fread(&x,sizeof(int),1,f1);                         //reading into x
    el2=fread(&y,sizeof(int),1,f2);                         //reading into y 
    
      
    int i=0,j=0;   
                         
    while(i<lsize && j<lsize)
    {   
        if(!(el1 && el2))
        {
        	break;
        }
        if(x<y)                  
        {
            fwrite(&x,sizeof(int),1,t);                 //WRITING y into temp file when y is smaller
            printf("%d ",x);
            i++;
            if(i<lsize)
            {
               el1=fread(&x,sizeof(int),1,f1);              //reading next element of list
            }
        }
        else                          
        {
            fwrite(&y,sizeof(int),1,t);                //writing x into temp file
            printf("%d ",y);
            j++;
            if(j<lsize)
            {
                el2=fread(&y,sizeof(int),1,f2);            //reading next element of list
            }
        }
        
        
    }
    while(i<lsize && el1)                                    //cases when one list got over
    {
        fwrite(&x,sizeof(int),1,t);
        printf("%d ",x);
        i++;
        if(i<lsize)
        {
            el1=fread(&x,sizeof(int),1,f1);
            
        }
    }
    while(j<lsize && el2)                         
    {
        fwrite(&y,sizeof(int),1,t);
        printf("%d ",y);
        j++;
        if(j<lsize)
        {
            el2=fread(&y,sizeof(int),1,f2);
            
        }
    }
    
    return el1&&el2;

}

void merge_sort(FILE *f1, FILE *f2,FILE *t,long size,int lsize)
{
    
        //while(lsize<=size)
        //{
		fseek(f2,sizeof(int)*lsize,SEEK_SET);                   //seeking to beginning of list 
		int c=1;
		while(c)
		{   
		    c=merge(f1,f2,t,lsize);                               //calling merge function
            printf("\t");
		    fseek(f1,lsize*sizeof(int), SEEK_CUR);              //seeking to begining of next list
		    fseek(f2,lsize*sizeof(int), SEEK_CUR);
		}
        printf("\n");
		
		fclose(f2);
		fclose(f1);
		fclose(t);
		
		
		int temp;
		int x;
		f1=fopen("input1.txt","w");
		t=fopen("temp.txt","r");
		while(1)
		{
			x=fread(&temp,sizeof(int),1,t);
			if(x!=1) break;
		    	fwrite(&temp,sizeof(int),1,f1);                     //copying sorted file into f1
		}
		if(lsize>size) return;
		fclose(f1);
		fclose(t);
		
		f1=fopen("input1.txt","r");
		f2=fopen("input1.txt","r");
		t=fopen("temp.txt","w");
		merge_sort(f1,f2,t,size,lsize*2);			//modifying list size and calling function recursively 
		//lsize*=2;
        //}
                                                      
        
    
}

int main()
{
    
    FILE *p,*q;
    
    p=fopen("input1.txt","r");
                    		//pointer to read and write from input            
    q=fopen("input1.txt","r");                  //pointer to read from input file
    FILE *ptr;
      
    ptr=fopen("temp.txt","w");                 //pointer to write into temp file
    fseek(p,0,SEEK_END);                        //seeking to end of file
    long size=(ftell(p))/sizeof(int);           //storing the number of elements in files to size variable
    fseek(p,0,SEEK_SET);                        //setting the pointer to beginning of the file
    long lsize=1;                                

    merge_sort(p,q,ptr,size,lsize);             //calling merge sort

    return 0;
}
