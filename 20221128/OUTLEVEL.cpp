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

int n, k, a[29];
int dp[29][29];

int32_t main() {
#define TASKNAME "OUTLEVEL"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> k >> n;
	memset(dp, 0, sizeof dp);
	FOR(i, 1, k) {
		FOR(j, 1, n) cin >> a[j];
		FOR(j, 2, n) {
			FOR(z, 1, j - 1) dp[a[z]][a[j]]++;
			//cout << a[z] << ' ' << a[j] << '\n';
		}
	}
	int len = 0;
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			len = len + (i != j && dp[j][i] == 0 ? 1 : 0);
			//cout << j << ' ' << i << '\n';
		}
	}
	cout << len;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3 4
4 1 2 3
4 1 3 2
4 2 1 3
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
4
------------------------------    |
==================================+
*/
