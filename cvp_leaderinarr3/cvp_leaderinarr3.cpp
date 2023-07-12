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

int t, n, a[N], b[N];

void solve() {
	cin >> n;
	map<int, int> d;
	for(int i = 0; i < n; i++) cin >> a[i];
	b[n - 1] = a[n - 1];
	for(int i = n - 2; i >= 0; i--) b[i] = max(b[i + 1], a[i]);
	vector<int> v;
	for(int i = 0; i < n; i++) {
		if(d[b[i]] == 0) v.pb(b[i]);
		d[b[i]]++;
	}
	each(i, v) cout << i << ' ';
	cout << '\n';
}

int32_t main() {
#define TASKNAME "cvp_leaderinarr3"
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
