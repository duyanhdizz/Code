#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll unsigned long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

ll n, t;
ll a[N];

bool check(ll f) {
	ll solg = 0;
	for(int i = 0; i < n; i++) {
		//if(solg > t) return false;
		solg += (f / a[i]);
	}
	return (solg >= t);
}

int32_t main() {
#define TASKNAME "WMDAY"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> t;
	for(int i = 0; i < n; i++) cin >> a[i];
	ll lo = 1, hi = 1e18;
	ll res = 1e18;
	while(lo <= hi) {
		ll mid = (lo + hi) / 2;
		if(check(mid) == true) {
			//res = min(res, mid);
			//cout << mid << '\n';
			//lo = mid + 1;
			hi = mid - 1;
		} else lo = mid + 1;
	}
	cout << lo;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3 7
3 2 5
---
4 10
3 7 9 2
---
5 13
6 8 10 14 26
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
8
---
10
---
30
------------------------------    |
==================================+
*/
