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
const int N = 9 + 3e5;
const int INF = 1e9;

int t, a[N];

void solve() {
	int n;
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	int x = -1, y = -1;
	int i = 1;
	while(i <= n && (x == -1 || y == -1)) {
		int j = i + 1;
		while (j <= n && a[j] == a[i]) j++;
		int c = j - i;
		if (c >= 2) if (x == -1) x = a[i], c -= 2;
		if (c >= 2) if (y == -1) y = a[i];
		i = j;
	}
	cout << ((x != -1 && y != -1) ? 1ll * x * y : -1) << '\n';
}

int32_t main() {
#define TASKNAME "dhrect"
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
