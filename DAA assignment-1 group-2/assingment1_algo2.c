//check if given number is fibonnaci or not
#include <stdio.h>
#define ll long long 
ll t=0;
ll Sqrt(ll x)
{
	// base case
	if (x < 2){
		t++;
		return x;
	}

	// to store floor of sqrt(x)
	ll result;

	// square root of x cannot be more than x/2 for x > 1
	ll start = 1;
	ll end = x/2;
	t+=3;
	while (start <= end)
	{
		t++;
		// find mid element
		ll mid = (start+end)/2;
		long sqr = mid*mid;
		t+=6;

		// return mid if x is a perfect square
		if (sqr == x)
			{
				t++;
				return mid;
			}
		// if mid*mid is less than x
		else if (sqr < x)
		{
			t++;
			// discard left search space
			start = mid + 1;
			t+=2;
			// update result since we need floor
			result = mid;
			t++;
	 }

		// if mid*mid is more than x
		else
		{
			// discard right search space
			end = mid - 1;
			t+=2;
		}
	}

	return result;
}
int check_fib(ll n)
{
    long long a = 5*n*n + 4;
    t+=5;
    ll ot=t;
    long long s = Sqrt(a);
    if(s*s == a){
    	t+=2;
    return 1;
	}
    a-=8;
    t+=2;
    s=Sqrt(a);
    if(s*s == a){
    	t+=2;
    return 1;
	}
    return 0;
}
int main()
{
    ll n;
    FILE *fptr,*fp;
    fptr = fopen("x2.txt","w");
    fp = fopen("y2.txt","w");
	if(fptr==NULL || fp==NULL)
    {
    	printf("error!");
    	exit(0);
	}
    for(n=1;n<=100000000;n*=2){
    	t=0;
    	long long l=0,or=n;
    	while(or>>=1){
			++l;
		}
    	check_fib(n);
    	if(check_fib(n)==1)
    	printf("yes\n");
    	else
    	printf("no\n");
		
		fprintf(fptr,"%lld , ",l);
		fprintf(fp,"%lld , ",t);
	}
    return 0;
}

