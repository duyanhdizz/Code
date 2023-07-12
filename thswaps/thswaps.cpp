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
const int N = 9 + 3e5;
const int INF = 1e9;

int n, a[N], bit[N], q;

#define _(x) ((x) & (-(x)))

inline void update(int k) {
	while (k <= N) {
		bit[k]++;
		k += _(k);
	}
}

inline int get(int x) {
	int res = 0;
	while (x > 0) {
		res += bit[x];
		x -= _(x);
	}
	return res;
}

void solve() {
	int x, y;
	cin >> x >> y;
	a[x] = y;
	memset(bit, 0, sizeof bit);
	int res = 0;
	FORD(i, n, 1) {
		res += get(a[i] - 1);
		update(a[i]);
	}
	cout << res << '\n';
}

int32_t main() {
#define TASKNAME "thswaps"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	cin >> q;
	while(q--)
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
