#include<stdio.h>
void space(int);
int j;
int main() {
   int i,j,n,count;
   scanf("%d",&n);
   char *str;
   str = (char *)malloc(sizeof(char) * n);
   scanf("%s",str);
   printf("String %s\n",str);
   count = n-1;
   for(i=1;i<=(n/2)+1;i++)
   {
        if(count==0)
       {
          space(i-1);
           printf("%c",*(str+i-1));
           break;
       }
       if(count!=0)
       {
           space(i-1);
           printf("%c",*(str+i-1));
           space(count);
           printf("%c",*(str+i-1));
           count-=2;
       }
       printf("\n");
   }
   j=(n/2)-1;
   for(i=(n/2)+2;i<=n;i++)
   {
       printf("\n"); 
       
        count+=2;
           space(j--);
           printf("%c",*(str+i-1));
           space(count);
           printf("%c",*(str+i-1));
           
       
       
   }
}
void space(int c)
{
    for(j=0;j<c;j++)
    {
       printf(".");
    }
}
