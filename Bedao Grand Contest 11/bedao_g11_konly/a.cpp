#include <bits/stdc++.h>
#define ll int
using namespace std;
const int d=1e9+7;
const int c=6e3;
ll a,t,b,i,j,res,x,y,k,n,m,op;
int main() {
	cin>>t;
	while(t--) {
		res=0;
		cin>>a>>b>>x>>y>>k;
		k=abs(k);
		if(k==0) {
			cout<<0<<"\n";
			continue;
		}
		b/=k;
		y/=k;
		if(a%k!=0) a=a/k+1;
		else a/=k;
		if(x%k!=0) x=x/k+1;
		else x/=k;
		/*
		x - y /  
		*/
		for(i=a; i<=b; i++)
			for(j=x; j<=y; j++)
				if() {
					//	cout<<i<<" "<<j<<"\n";
					res=(res+i*j*k*k)%d;
				}
		cout<<res<<"\n";
	}
	return 0;
}
