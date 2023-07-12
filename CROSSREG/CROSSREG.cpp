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
const int N = 9 + 50;
const int INF = 1e9;

char a[N][N];

int32_t main() {
#define TASKNAME "CROSSREG"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int n, m;
	cin >> n >> m;
	FOR(i, 1, n)
	FOR(j, 1, m)
	cin >> a[i][j];
	vector<pii> res;
	FOR(i, 1, n) {
		int cnt = 0;
		FOR(j, 1, m) {
			if(a[i][j] == '.') {
				cnt++;
				if(cnt == 3) res.pb({i, j - 2});
			} else cnt = 0;
		}
	}
	FOR(j, 1, m) {
		int cnt = 0;
		FOR(i, 1, n) {
			if(a[i][j] == '.') {
				cnt++;
				if(cnt == 3) res.pb({i - 2, j});
			} else cnt = 0;
		}
	}
	if(res.size() == 0) return cout << 0, 0;
	sort(all(res));
	int pos = 1;
	REP(i, 1, res.size())
	if(res[i].fi != res[i - 1].fi || res[i].se != res[i - 1].se) pos++;
	cout << pos << '\n';
	cout << res[0].fi << ' ' << res[0].se << '\n';
	REP(i, 1, res.size())
	if(res[i].fi != res[i - 1].fi || res[i].se != res[i - 1].se) cout << res[i].fi << ' ' << res[i].se << '\n';
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
