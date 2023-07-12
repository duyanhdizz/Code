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

int n, m, sumL[N], sumR[N];

int32_t main() {
#define TASKNAME "fct014_ribgame"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		int l, r, s;
		cin >> l >> r >> s;
		sumL[r] += s;
		sumR[l] += s;
	}
	for(int i = 2; i <= m; i++) sumL[i] += sumL[i - 1];
	for(int i = m - 1; i >= 1; i--) sumR[i] += sumR[i + 1];
	int ans = 0;
	for(int i = 1; i <= m; i++) ans = max(ans, sumL[i - 1] + sumR[i + 1]);
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
