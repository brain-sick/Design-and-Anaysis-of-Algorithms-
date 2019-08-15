#include<bits/stdc++.h>
using namespace std;
#define N 11
#define pb push_back
int n,q,d,S,D;
vector<pair<int,int>> adj[N]; 
bool vis[N]={false};
int dist=0,min_dist=INT_MAX;

void dfs(int node)
{
	if(vis[node]==true)
	return ;
	if(node==D)
	{
		min_dist = min(min_dist,dist);
		return;
	}
	
	vis[node]=true;

	for(int i=0;i<adj[node].size();i++)
	{
		if(vis[adj[node][i].first]==false)
		{
			dist+=adj[node][i].second;
			dfs(adj[node][i].first);
			dist-=adj[node][i].second;
		}
	}
}
int main()
{ 
	cin>>n;
	cin>>q;
	cin>>d;
	cin>>S>>D;
	while(q--)
	{
		int x,y,w;
		cin>>x>>y>>w;
		adj[x].pb(make_pair(y,w));
		if(d==0)
		{
			adj[y].pb(make_pair(x,w));
		}
	}
	
	dfs(S);
	if(min_dist==INT_MAX)
	cout<<S<<" and "<<D<<" are not connected";
	else
	cout<<min_dist<<"\n";
	return 0;
}