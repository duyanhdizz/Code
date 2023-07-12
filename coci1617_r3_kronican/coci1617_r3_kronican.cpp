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
#define BIT(n , i) ((n >> i) & 1)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int n, k;
ll res = 1e18;
int dp[(1LL << 20) + 9];
int cost[22][22];

void solve() {
	cin >> n >> k;
	FOR(i, 0, n - 1) FOR(j, 0, n - 1) cin >> cost[i][j];

	FOR(i, 0, (1ll << n) - 1) dp[i] = INF;

	if (k == n) {
		cout << 0 << '\n';
		return;
	}

	dp[(1LL << n) - 1] = 0;

	FORD(mask, (1ll << n) - 1, 1)
	if (__builtin_popcount(mask) > k) {
		FOR(i, 0, n - 1)
		if (BIT(mask, i))
			FOR(j, 0, n - 1)
			if (BIT(mask, j) && i != j) {
				dp[mask ^ (1LL << i)] = min (dp[mask ^ (1LL << i)], dp[mask] + cost[i][j]);
				if (__builtin_popcount(mask) == k + 1) res = min(res, 1LL * dp[mask ^ (1LL << i)]);
			}
	}
	cout << res << '\n';
}

int32_t main() {
#define TASKNAME ""
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	solve();
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
