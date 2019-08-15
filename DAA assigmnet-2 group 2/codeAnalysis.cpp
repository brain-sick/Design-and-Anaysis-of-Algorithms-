#include <iostream>
using namespace std;
struct A{
  int v,i;  
};
int t=0;
string to_string(int n)
{
	int r,k=3;
	string s="0000";
	while(n)
	{
		r=n%10;
		n/=10;
		s[k--]=r+'0';
	}
	return s;
}
int multiply(int a,int b)
{
    int ans=0;  
    int c=b;
    b>>=1;t+=4;
	t++;
    for(int i=1;i<=b;i++,t+=3)
    {
        ans += a;t=t+2;
    }
    
    ans+=ans;t=t+2;
    if(c&1){
    ans +=a;t=t+4;}
	else{
	t+=2; 	
	}
    return ans;
}
int toint(string s,int n)
{
    int res=0; t++;
	t++;
    for(int i=0;i<=n;i++,t+=3)
    {
        res = multiply(res,10) + s[i]-'0';t+=4;
    }
    return res;
}
A search(int z,int x)
{
    int p=0,i=0,temp;
	t+=2;
    while(1){
        temp = p+x;t=t+2;
        if(temp>z){
        break;t=t+1;}
		else{t=t+1;}
        p+=x;
        i++;t=t+3;
    }
    A ans;
    ans.v=p;
    ans.i=i;t=t+2;
    return ans;
}
int main()

{	FILE *ftr1,*ftr2,*ftr3;
	ftr1=fopen("x.txt","w");
	ftr2=fopen("y.txt","w");
	ftr3=fopen("z.txt","w");
	
	if(ftr1==NULL ||ftr2==NULL ||ftr3==NULL){
		printf("error");
		exit(0);
	}
	for(int p=1000;p<=9999;p=p+300)
	{
		for(int x=10;x<=99;x+=10){
			t=0;
    string s = to_string(p);
    //int x;
	int n=1;
    
    int z=toint(s,n);
    if(z<x)
    {
        z=multiply(z,10)+s[++n]-'0';t=t+7;
    }
	else{t=t+1;}
    A k = search(z,x);
    int r =  z -k.v;
    int q = k.i;
	t+=3;
    while(n<3)
    {
        r  = multiply(r,10) + s[++n] -'0';t=t+6;
        if(!s[n]){
            q = multiply(q,10);t=t+3;
        }
		else
			t+=2;
        while(r<x && n<3)
        {
            r = multiply(r,10) + s[++n] -'0';t=t+9;
            q = multiply(q,10);t++;
        }
        k = search(r,x); t++;
        r = r-k.v;t=t+2;
        q = multiply(q,10) + k.i;t=t+2;
    }
  
    fprintf(ftr1,"%lld ,",p);
    fprintf(ftr2,"%lld ,",x);
    fprintf(ftr3,"%lld ,",t);
    //cout<<s<<" "<<x<<" quotient = "<<q<<" remainder = "<<r<<"\n";
		}
	}
    return 0;
}
