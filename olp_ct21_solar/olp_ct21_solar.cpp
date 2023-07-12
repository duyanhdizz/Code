#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define REP(i, a, b) for (int i = (a); i < (int) (b); ++i)
#define each(a, x) for (auto &a : x)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int n, q, a[N], st[N];

void build(int id,int l,int r) {
	if(l==r) {
		st[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=max(st[id*2],st[id*2+1]);
}
void update(int id,int l,int r,int i,int v) {
	if(i<l||i>r) return;
	if(l==r) {
		st[id]=v;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,i,v);
	update(id*2+1,mid+1,r,i,v);
	st[id]=max(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v) {
	if(u>r||v<l) return LLONG_MIN;
	if(u<=l&&v>=r)
		return st[id];
	int mid=(l+r)/2;
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

int32_t main() {
#define TASKNAME "olp_ct21_solar"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cout << "HELLO WORLD";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
