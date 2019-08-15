#include <iostream>
using namespace std;
#define N 10000
int wt[N+1],val[N+1];
int n,w;
struct R{
    int i;
    float r;
};
struct R ppw[N+1];
void swap(struct R *a,struct R *b)
{
    struct R temp;
    temp.i = a->i;
    temp.r = a->r;
    a->i = b->i;
    a->r = b->r;
    b->i = temp.i;
    b->r = temp.r;
}
void heapify(struct R ppw[],int i,int n)
{
    int best=i;
    int lc=2*i+1,rc=2*i+2;
    if(lc<n && ppw[lc].r>=ppw[best].r)
    best = lc;
    if(rc<n && ppw[rc].r>ppw[best].r)
    best = rc;
    if(best!=i)
    {
        swap(&ppw[best],&ppw[i]);
        heapify(ppw,best,n);
    }
}
void heapsort(struct R ppw[])
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(ppw,i,n);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(&ppw[0],&ppw[i]);
        heapify(ppw,0,i);
    }
}
int main()
{
    cout<<"enter number of elements : ";
    cin>>n;
	cout<<"enter weight of knapsack : ";
    cin>>w;
    cout<<"enter weight and value of elements : \n";
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
        ppw[i].i=i;
        ppw[i].r=((float)val[i])/((float)wt[i]);
    }
    heapsort(ppw);
    float curr_wt = 0.0;
    float ans=0;
    int idx=n-1;
    while(curr_wt<w && idx>=0)
    {
       
        if(wt[ppw[idx].i]<=w-curr_wt)
        {
            ans+=val[ppw[idx].i];
            curr_wt += wt[ppw[idx].i];
        }
        else{
            ans+=(ppw[idx].r)*(w-curr_wt);
            curr_wt = w;
        }
        idx--;
    }
    cout<<"maximum value of knapsack : " << ans;
    return 0;
}
