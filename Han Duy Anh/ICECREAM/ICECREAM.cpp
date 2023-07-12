#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int n, x;

int32_t main() {
#define TASKNAME "ICECREAM"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> x;
	vector<pii> v(n);
	for(int i = 0; i < n; i++) cin >> v[i].fi >> v[i].se;
	int res = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			if(v[i].fi + v[j].fi <= x) res = max(res, v[i].se + v[j].se);
		}
	}
	cout << res;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3 10
1 1
5 4
9 8
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
9
------------------------------    |
==================================+
*/