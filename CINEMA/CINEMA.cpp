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
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e5;
const int INF = 1e9;

int32_t main() {
#define TASKNAME "CINEMA"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int n;
	vector<pii> p_b_a, p_c_a;
	cin >> n;
	int sum = 0;
	FOR(i, 1, n) {
		int a, b, c;
		cin >> a >> b >> c;
		sum += a;
		p_b_a.pb({b - a, i});
		p_c_a.pb({c - a, i});
	}
	sort(all(p_b_a), [&](pii l, pii r) {
		if(l.fi > r.fi) return true;
		if(l.fi < r.fi) return false;
		return (l.se <= r.se);
	});
	sort(all(p_c_a), [&](pii l, pii r) {
		if(l.fi > r.fi) return true;
		if(l.fi < r.fi) return false;
		return (l.se <= r.se);
	});
	if(p_b_a[0].se == p_c_a[0].se) {
		if(p_c_a[0].fi == p_c_a[1].fi) swap(p_c_a[0], p_c_a[1]);
		else if(p_b_a[1].fi == p_b_a[0].fi) swap(p_b_a[0], p_b_a[1]);
	}
	if(p_b_a[0].se == p_c_a[0].se) {
		if(p_b_a[0].fi + p_c_a[1].fi == p_b_a[1].fi + p_c_a[0].fi) {
			if(p_b_a[0].se < p_b_a[1].se) cout << sum + p_b_a[0].fi + p_c_a[1].fi << '\n' << p_c_a[0].se << ' ' << p_b_a[1].se;
			else if(p_b_a[0].se == p_b_a[1].se)
				if(p_c_a[0].se < p_c_a[1].se) cout << sum + p_b_a[1].fi + p_c_a[0].fi << '\n' << p_b_a[1].se << ' ' << p_c_a[0].se;
				else cout << sum + p_b_a[0].fi + p_c_a[1].fi << '\n' << p_c_a[0].se << ' ' << p_b_a[1].se;
			else cout << sum + p_b_a[1].fi + p_c_a[0].fi << '\n' << p_b_a[1].se << ' ' << p_c_a[0].se;
		} else if(p_b_a[0].fi + p_c_a[1].fi > p_b_a[1].fi + p_c_a[0].fi) cout << sum + p_b_a[0].fi + p_c_a[1].fi << '\n' << p_b_a[0].se << ' ' << p_c_a[1].se;
		else cout << sum + p_b_a[1].fi + p_c_a[0].fi << '\n' << p_b_a[1].se << ' ' << p_c_a[0].se;
	} else cout << sum + p_b_a[0].fi + p_c_a[0].fi << '\n' << p_b_a[0].se << ' ' << p_c_a[0].se;
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3
3 6 9
1 5 7
1 3 9
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
