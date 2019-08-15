//check if given number is fibonnaci or not
#include <stdio.h>
#include<stdlib.h>
int check_fib(long long n,long long *t)
{
	
    long long a=0,b=1,c;
    if(n==a){
    	(*t)++;
    	return 1;
	}
	if(n==b)
	{
		(*t)++;
    	return 1;
	}
    c=a+b;
    (*t)+=2;
    while(c<=n)
    {
    	(*t)++;
        if(c==n){
        	(*t)++;
			return 1;
    	}
        else{
            a=b;
            b=c;
            c=a+b;
            (*t)+=4;
        }
    }
    (*t)++;
    return 0;
}
int main()
{
    long long n,t=0;
    FILE *fptr,*fp;
    fptr = fopen("x.txt","w");
    fp = fopen("y.txt","w");
	if(fptr==NULL || fp==NULL)
    {
    	printf("error!");
    	exit(0);
	}
    for(n=1;n<=1000000000000;n*=2)
    {
    	t=0;
		if(check_fib(n,&t)==1)
		printf("yes\n");
		else
		printf("no\n");
    	long long l=0,or=n;
    	while(or>>=1){
			++l;
		}
		fprintf(fptr,"%lld , ",l);
		fprintf(fp,"%lld , ",t);	
	}
	return 0;
}
