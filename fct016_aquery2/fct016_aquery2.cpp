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
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int n, k;

int32_t main() {
#define TASKNAME "fct016_aquery2"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	vector<pii> v(n);
	each(x, v) cin >> x.fi >> x.se;
	cin >> k;
	sort(all(v));
	REP(i, 0, v.size()) {
		k -= v[i].se;
		if(k <= 0) {
			cout << v[i].fi;
			break;
		}
	}
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3
5 2
2 3
3 1
4
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
3
------------------------------    |
==================================+
*/
