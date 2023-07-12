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
const int N = 10000;
const int INF = 1e9;

int f[N + 1][N / 10 + 1], n, W, v[N + 1], w[N + 1], stk[N];

int32_t main() {
#define TASKNAME "hugeknap"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> W;
		for(int i = 1; i <= n; ++i) cin >> w[i];
		for(int i = 1; i <= n; ++i) cin >> v[i];
		for(int i = 1; i <= n; ++i) {
			for(int j = w[i]-1; j > 0; --j)
				f[i][j] = f[i-1][j];
			for(int j = w[i]; j <= W; ++j)
				f[i][j] = max(f[i-1][j], v[i]+f[i-1][j-w[i]]);
		}
		int i = n, j = W, hi = 0;
		while(i && j) {
			if(f[i][j] == f[i-1][j]) --i;
			else {
				stk[hi++] = i;
				j -= w[i--];
			}
		}
		cout << f[n][W] << ' ' << hi << '\n';
		while(hi--) cout << stk[hi] << ' ';
		cout << '\n';
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
