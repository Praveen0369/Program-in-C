#include<stdio.h>  
 int main()    
{    
int n,r,add=0,t;    
printf("enter the number=");    
scanf("%d",&n);    
t=n;    
while(n>0)    
{    
r=n%10;    
add=add+(r*r*r);    
n=n/10;    
}    
if(t==add)    
printf("armstrong  number ");    
else    
printf("not armstrong number");    
return 0;  
}
