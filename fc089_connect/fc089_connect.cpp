#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int n;

int32_t main() {
#define TASKNAME ""
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	vector<pii> v(2 * n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> v[i].fi;
		v[i].se = 0;
	}
	for(int i = n + 1; i <= 2 * n; i++) {
		cin >> v[i].fi;
		v[i].se = 1;
	}
	sort(all(v));
	int res = 0, ans = 1;
	for(int i = 1; i <= 2 * n; i++) {
		if (v[i].se == 0) {
			if (res < 0) ans = (1LL * ans * (-res)) % MOD;
			res++;
		} else {
			if (res > 0) ans = (1LL * ans * res) % MOD;
			res--;
		}
	}
	cout << ans;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
2
50 60
70 80
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
2
------------------------------    |
==================================+
*/
