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

int n, m, Q;
ll a[501][501];

int32_t main() {
#define TASKNAME "dhbb2022table"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m >> Q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	while (Q--) {
		int t;
		cin >> t;

		if (t == 1) {
			int x, y, u, v, w;
			cin >> x >> y >> u >> v >> w;

			for (int i = x; i <= u; i++) {
				for (int j = y; j <= v; j++) {
					a[i][j] += w;
				}
			}
		} else {
			int x, y, u, v;
			cin >> x >> y >> u >> v;

			ll ans = 0;
			for (int i = x; i <= u; i++) {
				for (int j = y; j <= v; j++) {
					ans += a[i][j];
				}
			}

			cout << ans << "\n";
		}
	}
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
