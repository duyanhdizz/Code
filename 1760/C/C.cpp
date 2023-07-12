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
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int t;

void solve() {
	int n;
	cin >> n;
	vector<pii> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i].fi;
		v[i].se = i;
	}
	sort(all(v));
	int res = v[n - 1].fi;
	for(int i = n - 1; i >= 0; i--) {
		if(i == n - 1) v[n - 1].fi -= v[n - 2].fi;
		else v[i].fi -= res;
	}
	for(int i = 0; i < n; i++) swap(v[i].fi, v[i].se);
	sort(all(v));
	for(auto i : v) cout << i.se << ' ';
	cout << '\n';
}

int32_t main() {
#define TASKNAME "C"
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
