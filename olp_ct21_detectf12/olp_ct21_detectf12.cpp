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
const int N = 9 + 1e3;
const int INF = 1e9;

int n, f0, d, x[N], y[N], m[N];

int32_t main() {
#define TASKNAME "olp_ct21_detectf12"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> f0 >> d;
	d *= d;
	int tr, ph;
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		//m[i] = 0;
		if(i == f0) {
			tr = x[i];
			ph = y[i];
		}
	}
	int f1 = 0, f2 = 0;
	vector<pii> v, vv;
	for(int i = 1; i <= n; i++) {
		if(i != f0) {
			if((tr - x[i]) * (tr - x[i]) + (ph - y[i]) * (ph - y[i]) <= d) {
				f1++;
				v.pb({x[i], y[i]});
			} else vv.pb({x[i], y[i]});
		}
	}
	for(int i = 0; i < v.size(); i++) {
		for(int j = 0; j < vv.size(); j++) {
			if((vv[j].fi - v[i].fi) * (vv[j].fi - v[i].fi) + (vv[j].se - v[i].se) * (vv[j].se - v[i].se) <= d) {
				f2++;
			}
		}
	}
	cout << f1 << ' ' << f2;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
5 4 2
2 2
0 0
0 2
1 1
2 3
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
3 1
------------------------------    |
==================================+
*/
