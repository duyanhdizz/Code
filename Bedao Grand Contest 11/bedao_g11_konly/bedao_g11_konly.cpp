#include <bits/stdc++.h>
#define ll int
using namespace std;
const int d=1e9+7;
const int c=1000;
bool snt[c+2];
int a,t,b,res,x,y,k,n,m;
vector<pair<int, int>> v;

bool tknp(int x, int y) {
	int lo = 0, hi = v.size() - 1;
	while(lo <= hi) {
		int mid = (lo + hi) / 2;
		if(v[mid].first > x) {
			hi = mid - 1;
		} else if(v[mid].first < x) {
			lo = mid + 1;
		} else {
			if(v[mid].second == y) return true;
			else if(v[mid].second > y) hi = mid - 1;
			else lo = mid + 1;
		}
	}
	return false;
}

int main() {
	for(int i=2; i<=c; i++)
		if(snt[i]==0) {
			v.push_back({i, i});
			for(int j=2; j<=c/i; j++) {
				for(int op=1; op<=j; op++) {
					v.push_back({i*op, i*j});
					v.push_back({i*j, i*op});
				}
				snt[i*j]=1;
			}
		}
	sort(v.begin(), v.end());
	//  cout<<dem[{2,4}];return 0;
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
		for(int i=a; i<=b; i++)
			for(int j=x; j<=y; j++)
				if(tknp(i, j) == false) {
					//cout<<i<<" "<<j<<"\n";
					res=(res+i*j*k*k)%d;
				}
		cout<<res<<"\n";
	}
	return 0;
}
/*
1 1
1 2
1 3
1 4
1 5
2 1
2 3
2 5
3 1
3 2
3 3
3 4
3 5
4 1
4 3
4 5
5 1
5 2
5 3
5 4
*/