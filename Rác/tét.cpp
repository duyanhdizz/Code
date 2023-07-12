#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize ("Ofast")
#define rep(i,a,n,b) for(int i=(a);i<=(n);i+=b)
#define el cout<<'\n';
#define ed <<'\n';
string s,w="";
const int N=100005;
int n;
ll a[N+2],tree[N*4];
void buildtree(int id,int l,int r) {
	if(l == r) {
		tree[id]=a[l];
		return;
	}
	int m=(l+r)/2;
	buildtree(id*2,l,m);
	buildtree(id*2+1,m+1,r);
	tree[id]=(tree[id*2] + tree[id*2+1]);
}

void update(ll id,ll l,ll r,ll i,ll v) {
	if(i<l || i>r) return;
	if(l == r) {
		tree[id]=v;
		return;
	}
	int m=(l+r)/2;
	update(id*2,l,m,i,v);
	update(id*2+1,m+1,r,i,v);
	tree[id]=tree[id*2]+tree[id*2+1];
}

ll get(ll id,ll l,ll r,ll u,ll v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return tree[id];
	int m=(l+r)/2;
	return (get(id*2,l,m,u,v)+get(id*2+1,m+1,r,u,v));
}

void solve() {
	ll     x,y;
	cin>>x>>y;
	a[x] = 0;
	update(1,1,n,x,y);
}

void giai() {
	ll l,r;
	cin>>l>>r;
	cout<<get(1,1,n,l,r) ed
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int testcase;
	cin>>testcase;
	for(int i = 1; i <= n; i++) cin >> a[i];
	while(testcase --> 0) {
		int x;
		cin>>x;
		if(x == 1) solve();
		else giai();
	}

	return 0;
}
