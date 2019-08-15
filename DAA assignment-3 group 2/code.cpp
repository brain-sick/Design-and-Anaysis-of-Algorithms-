#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(0));
	// your code goes here
	int n;
	cin>>n;
	int a[n][n];//general n*n matrix
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]= rand()%10;   // random number generator
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//int max=a[0][0];
	int maxl  = 2;
	for(int k=0;k<=n-1;k++){
		int i=k;
		int j=0;
		int li=1;
	    int ld=1;
		while(i>=0){
			if(j!=0 ){
				if(a[j][i]>a[j-1][i+1]){
					li++;
					maxl = max(maxl,li);
					ld=1;
				}
				else if(a[j][i]<a[j-1][i+1])
				{
				    ld++;
				    maxl = max(maxl,ld);
					li=1;
				}
				else{
				    li++;
				    ld++;
				    maxl = max(maxl,li);
				    maxl = max(maxl,ld);
				}
			}
			cout<<a[j][i]<<" ";
			i=i-1;
			j=j+1;
		}
		cout<<endl;
	}
	for(int k=1;k<=n-1;k++){
		int i=n-1;
		int j=k;
		int li=1,ld=1;
		while(j<=n-1){
			if(i!=n-1){
				if(a[j][i]>a[j-1][i+1]){
					li++;
					maxl = max(maxl,li);
				}
				else if(a[j][i]<a[j-1][i+1]){
					ld++;
					maxl = max(maxl,ld);
				}
				else
				{
				    li++;
				    ld++;
				    maxl = max(maxl,li);
				    maxl = max(maxl,ld);
				}
			}
			cout<<a[j][i]<<" ";
			i=i-1;
			j=j+1;
		}
		cout<<endl;
	}
	
	cout<<"Length of largest sorted subsequence is "<<maxl;
	return 0;
}