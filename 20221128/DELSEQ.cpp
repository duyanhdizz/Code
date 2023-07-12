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
const int N = 9 + 1e5;
const int INF = 1e9;

int n;
map<int, int> m;

int32_t main() {
#define TASKNAME "DELSEQ"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 1, n) {
		int a;
		cin >> a;
		m[a]++;
	}
	vector<pii> v;
	each(x, m) v.pb({x.fi, x.se});
	sort(all(v), [&] (pii l, pii r) {
		return l.se > r.se;
	});
	int res = 0;
	FOR(i, 0, v.size() - 1) {
		if(v[i].se) {
			FOR(j, i + 1, v.size() - 1) {
				if(v[j].se) {
					int len = min(v[i].se, v[j].se);
					v[i].se -= len;
					v[j].se -= len;
					res += len;
					if(v[i].se == 0) break;
				}
			}
		}
	}
	each(x, v) res += x.se;
	//cout << x.fi << ' ' << x.se << '\n';
	cout << res;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
4
1 2 3 3
---
3 
1 1 1
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
2
---
3
------------------------------    |
==================================+
*/
