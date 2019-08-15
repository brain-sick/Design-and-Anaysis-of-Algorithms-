#include <bits/stdc++.h>
using namespace std;
int printv(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
}
int main()
{
    
    int target;
    cin>>target;
    vector<int> v;
    int sum=0,i=1,ctr=0;
    do
    {
        sum+=i;
        if(sum==target)
        ctr=1;
        i++;
    }while(sum<=target);
    if(ctr==1)
    {
      int s=0;
      i=1;
      while(s<=target)
      {
        s+=i;
        i++;
        if(s<=target)
        v.push_back(s);
      }
      cout<<"number of moves : "<<v.size()<<"\nPath:\n";
      printv(v);
      return 0;
    }
    while(abs((sum-target))%2!=0)
    {
        sum+=i;
        i++;
        
    }
    int rev = (sum-target)>>1;
    sum=0;
    int step=1;
    while(sum!=target)
    {
        if(step!=rev)
        {
            sum+=step;
        }
        else
        sum-=step;
        v.push_back(sum);
        step++;
    }
    cout<<"number of moves : "<<v.size()<<"\nPath:\n";
    printv(v);
    return 0;
}
