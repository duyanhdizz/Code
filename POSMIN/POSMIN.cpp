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

int n, a[N];

int32_t main() {
#define TASKNAME "POSMIN"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	a[0] = INF;
	FOR(i, 1, n) a[i] = min(a[i], a[i - 1]);
	int q;
	cin >> q;
	vector<pii> v(q);
	REP(i, 0, q) {
		cin >> v[i].fi;
		v[i].se = i;
	}
	sort(all(v));
	int pos = n;
	REP(i, 0, q) {
		while(v[i].fi >= a[pos]) pos--;
		v[i].fi = pos + 1;
	}
	REP(i, 0, q) swap(v[i].fi, v[i].se);
	sort(all(v));
	REP(i, 0, q) cout << v[i].se << '\n';
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
