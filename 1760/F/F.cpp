#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 2e5;
const int INF = 1e9;

int t, n, a[N];

bool check(int x, int c, int d) {
	int sum = 0;
	int solan = (d / min(n, (x + 1))), du = d % min(n, (x + 1));
	for(int i = 0; i < min(n, x + 1); i++) {
		if(i < du) sum += a[i];
		sum += solan * a[i];
	}
	//cout << sum << '\n';
	return (sum >= c);
}

void solve() {
	int c, d;
	cin >> n >> c >> d;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<>());
	if(a[0] >= c) {
		cout << "Infinity" << '\n';
		return;
	}
	if(a[0] * d < c) {
		cout << "Impossible" << '\n';
		return;
	}
	int lo = 1, hi = d - 1;
	int res = 0;
	while(lo <= hi) {
		int mid = (lo + hi) / 2;
		if(check(mid, c, d)) {
			res = max(res, mid);
			//cout << mid << '\n';
			lo = mid + 1;
		} else hi = mid - 1;
	}
	cout << res << '\n';
}

int32_t main() {
#define TASKNAME "F"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> t;
	while(t--)
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
