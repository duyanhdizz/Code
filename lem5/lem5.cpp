#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
const int N = 9 + 1e5;
const int INF = 1e9;

int n, dp[N];
pii a[N];

int32_t main() {
#define TASKNAME ""
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a + 1, a + n + 1);
	int ans = 1;
	FOR(d, 1, 100) {
		fill(dp + 1, dp + n + 1, 1);
		int i = 1, j = 1;
		while(i <= n) {
			while(j <= n && (a[j].fi - a[i].fi) < d) j++;
			int ki = i + 1;
			while(ki <= n && a[ki].fi == a[i].fi) ki++;
			int kj = j + 1;
			while(kj <= n && a[kj].fi == a[j].fi) kj++;
			if(a[j].fi - a[i].fi == d) {
				int len = 0;
				while(j < kj) {
					while (i < ki && a[i].se < a[j].se) len = max(len, dp[i++]);
					dp[j] = len + 1;
					j++;
				}
			}
			i = ki;
		}
		FOR(i, 1, n) ans = max(ans, dp[i]);
	}
	cout << ans;
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
