#include <iostream>
using namespace std;
struct A{
  int v,i;  
};
int multiply(int a,int b)
{
    int ans=0;
    int c=b;
    b>>=1;
    for(int i=1;i<=b;i++)
    {
        ans += a;
    }
    
    ans+=ans;
    if(c&1)
    ans +=a;
    return ans;
}
int toint(string s,int n)
{
    int res=0;
    for(int i=0;i<=n;i++)
    {
        res = multiply(res,10) + s[i]-'0';
    }
    return res;
}
A search(int z,int x)
{
    int p=0,i=0,temp;
    while(1){
        temp = p+x;
        if(temp>z)
        break;
        p+=x;
        i++;
    }
    A ans;
    ans.v=p;
    ans.i=i;
    return ans;
}
int main()
{
    string s;
    int x,n=1;
    cin>>s>>x;
    int z=toint(s,n);
    if(z<x)
    {
        z=multiply(z,10)+s[++n]-'0';
    }
    A k = search(z,x);
    int r =  z -k.v;
    int q = k.i;
    while(n<3)
    {
        r  = multiply(r,10) + s[++n] -'0';
        if(!s[n])
            q = multiply(q,10);
        while(r<x && n<3)
        {
            r = multiply(r,10) + s[++n] -'0';
            q = multiply(q,10);
        }
        k = search(r,x);
        r = r-k.v;
        q = multiply(q,10) + k.i;
    }
    cout<<"quotient = "<<q<<" remainder = "<<r<<"\n";
    return 0;
}
