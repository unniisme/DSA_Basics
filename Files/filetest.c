#include <stdio.h>
 
int main ()
{
 
   FILE *fp;
   fp = fopen ("test","w");
   long num, a=1, b=2,c=3;
   fwrite(&a, sizeof(long), 1, fp);
   fwrite(&b, sizeof(long), 1, fp);
   fwrite(&c, sizeof(long), 1, fp);
   fclose(fp);  
 
   fp = fopen ("test","r");

   fseek(fp, sizeof(long), SEEK_SET);
   fread(&num, sizeof(long), 1, fp);
   printf("%ld\n", num);

   fseek(fp, 8, SEEK_SET);
   fread(&num, sizeof(long), 1, fp);
   printf("%ld\n", num);
  
   fclose(fp);
   return 0;
}