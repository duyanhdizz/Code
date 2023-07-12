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
const int N = 9 + 1e2;
const int INF = 1e9;

int x[N], y[N], stop[N], ans[N];
vector<int> vn, ve;
vector<pair<pii, pii>> v;

int32_t main() {
#define TASKNAME "INFPAINT"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int n;
	cin >> n;
	FOR(i, 1, n) {
		char c;
		cin >> c >> x[i] >> y[i];
		if(c == 'E') vn.pb(i);
		else ve.pb(i);
	}
	REP(i, 0, vn.size()) {
		int x_ = x[vn[i]];
		int y_ = y[vn[i]];
		REP(j, 0, ve.size()) {
			int a = x[ve[j]];
			int b = y[ve[j]];
			if(a < x_) continue;
			if(b > y_) continue;
			int ma = a - x_;
			if( ma == y_ - b) continue;
			ma = max( ma, y_ - b );
			if( ma == a - x_ ) v.pb({{ma, y_ - b}, {vn[i], ve[j]}});
			else v.pb({{ma, a - x_}, {ve[j], vn[i]}});
		}
	}
	sort(all(v));
	REP(i, 0, v.size()) {
		if(stop[v[i].se.fi] ) continue;
		if(stop[v[i].se.se] && ans[v[i].se.se] <= v[i].fi.se ) continue;
		stop[v[i].se.fi] = 1;
		ans[v[i].se.fi] = v[i].fi.fi;
	}
	FOR(i, 1, n) {
		if(ans[i] == 0) cout << "Infinity" << '\n';
		else cout << ans[i] << '\n';
	}
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
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
