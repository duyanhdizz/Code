#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100009],i,n,q,x,y,k;
vector<ll> f[100009 * 4];
void build(ll id,ll l,ll r) {
    if (l == r) {
        f[id].push_back(a[l]);
        return ;
    }
    ll mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1, r);
    for(ll i=0;i<f[id*2].size();i++)
    f[id].push_back(f[id*2][i]);
    for(ll i=0;i<f[id*2+1].size();i++)
    f[id].push_back(f[id*2+1][i]);
    sort(f[id].begin(),f[id].end());
	}
ll res(ll id,ll l,ll r,ll u,ll v,ll k) {
    if (v<l||r<u) 
        return 0;
    if (u<=l&&r<=v) 
        return f[id].size()-(upper_bound(f[id].begin(),f[id].end(),k)-f[id].begin());
    ll mid=(l+r)/2;
    return res(id*2,l,mid,u,v,k)+res(id*2+1,mid+1,r,u,v,k);
}
int main() {
	cin >>n;
	for(i=1;i<=n;i++)
	cin >>a[i];
	cin >>q;
	build(1,1,n);
	while (q--){
		cin >>x>>y>>k;
		cout << res(1,1,n,x,y,k)<<"\n";
	}
	return 0;
}