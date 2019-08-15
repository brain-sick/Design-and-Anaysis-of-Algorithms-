#include <iostream>
using namespace std;
#define ll long long 
int main()
{
    int n,m;
    cout<<"enter size of array 1 : ";
    cin>>n;
    cout<<"\nenter size of array 2 : ";
    cin>>m;
    ll a[n+1],b[m+1],c[n+m+1];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    for(int j=0;j<m;j++)
    cin>>b[j];
    
    int i=0,j=0,k=0;
    while(i<n && j<m)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    while(i<n)
    {
        c[k]=a[i];
        i++; k++;
    }
    while(j<m)
    {
        c[k]=b[j];
        j++; k++;
    }
    cout<<"\nsorted final array\n";
    for(int z=0;z<k;z++)
    {
        cout<<c[z]<<" ";
    }
    return 0;
}

