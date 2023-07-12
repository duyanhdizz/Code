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
const int N = 9 + 1e3;
const int INF = 1e9;

ll n, m, a[N], b[N], c[N][N], psum[N][N];

int32_t main() {
#define TASKNAME "FISH"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < m; ++i) cin >> b[i];
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> c[i][j];
	for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            psum[i][j] = psum[i - 1][j] + c[i][j];
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int ii = i; ii < n; ii++) {
			ll res = 0, minRes = 1e18;
			for (int j = 0; j < m; j++) {
				minRes = min(minRes, res - b[j] * (a[ii] - a[i]));
				res += psum[ii][j] - psum[i - 1][j];
				ans = max(ans, res - b[j] * (a[ii] - a[i]) - minRes);
			}
		}
	}
	cout << ans;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
4 3
1 4 5 7
2 3 6
3 5 3
1 2 3
4 7 2
2 0 6
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
18
------------------------------    |
==================================+
*/
