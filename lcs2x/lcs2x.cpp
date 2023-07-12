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
const int N = 9 + 1e6;
const int INF = 1e9;

int32_t main() {
#define TASKNAME "lcs2x"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int t;
	cin >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;
		vector<int> a(m), b(n);
		each(x, a) cin >> x;
		each(x, b) cin >> x;
		vector<int> m_a_x(m, 0), dp(n, 0);
		int res = 0;
		REP(i, 0, m) {
			REP(j, 0, n) {
				int len = m_a_x[i];
				if (b[j] * 2 <= a[i]) m_a_x[i] = max(m_a_x[i], dp[j]);
				if (a[i] == b[j]) {
					dp[j] = len + 1;
					res = max(res, dp[j]);
				}
			}
		}
		cout << res << '\n';
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
