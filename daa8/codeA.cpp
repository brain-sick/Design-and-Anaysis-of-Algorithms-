#include <bits/stdc++.h>
using namespace std;
#define N 10000

int wt[N+1],val[N+1];
int n,w;
long long int t=0;
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
    t=t+6;
}
void heapify(struct R ppw[],int i,int n)
{
    int best=i;t++;
    int lc=2*i+1,rc=2*i+2;t=t+6;
    t+=3;
    if(lc<n && ppw[lc].r>=ppw[best].r){
	t++;
    best = lc;
	}
	t+=3;
    if(rc<n && ppw[rc].r>ppw[best].r){
	
	t++;
    best = rc;
	}
	t++;
    if(best!=i)
    {   
        swap(&ppw[best],&ppw[i]);
        heapify(ppw,best,n);
    }
}
void heapsort(struct R ppw[])
{	t=t+6;
    for(int i=n/2-1;i>=0;i--)
    {	
    	t=t+6;
        heapify(ppw,i,n);
    }
    t=t+5;
    for(int i=n-1;i>=0;i--)
    {
    	t=t+5;
        swap(&ppw[0],&ppw[i]);
        heapify(ppw,0,i);
    }
}
int main()
{	srand(time(0));
	FILE *ftr1,*ftr2;
	ftr1 = fopen("x.txt","w");
	ftr2 = fopen("y.txt","w");
	if(ftr1==NULL || ftr2==NULL)
	{
		cout<<"error\n";
	}
    int n;
    for(int i=1;i<=1000;i++){
		n=i;
		//cout<<"enter weight of knapsack : ";
	    //int w=rand()%10000;
	    //cout<<"enter weight and value of elements : \n";
	    t=t+4;
	    for(int i=0;i<n;i++)
	    {	
	    	t=t+4;
	        wt[i]=rand()%10000;
			val[i]=rand()%10000;
	        ppw[i].i=i;t+=5;
	        ppw[i].r=((float)val[i])/((float)wt[i]);t=t+2;
	    }
	    heapsort(ppw);
	    float curr_wt = 0.0;
	    float ans=0;
	    int idx=n-1;
	    t=t+3;
	    t=t+2;
	    while(curr_wt<w && idx>=0)
	    {	t=t+2;
	       	
	        if(wt[ppw[idx].i]<=w-curr_wt)
	        {	
	        	t++;
	            ans+=val[ppw[idx].i];
	            curr_wt += wt[ppw[idx].i];
	            t=t+4;
	        }
	        else{
	        	t++;
	            ans+=(ppw[idx].r)*(w-curr_wt);
	            curr_wt = w;
	            t=t+4;
	        }
	        idx--;
	        t=t+2;
	    }
	   // cout<<"maximum value of knapsack : " << ans;
	    fprintf(ftr1,"%d ,",n);
   		fprintf(ftr2,"%d ,",t);
	}
    return 0;
}
