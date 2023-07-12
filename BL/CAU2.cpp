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
const int N = 2106 + 1e6;
const int INF = 2106 + 1e9;

void dfs(vector<vector<int>>& g, vector<bool>& vis, int x) {
	vis[x] = true;
	each(y, g[x]) {
		if (!vis[y]) {
			dfs(g, vis, y);
		}
	}
}

int solve(int n, int m, vector<pii>& roads) {
	vector<vector<int>> g(n + 1);
	FOR(i, 0, m - 1) {
		int u = roads[i].fi;
		int v = roads[i].se;
		g[u].pb(v);
		g[v].pb(u);
	}
	int _ = 0;
	FOR(i, 0, m - 1) {
		int u = roads[i].fi;
		int v = roads[i].se;
		g[u].erase(find(all(g[u]), v));
		g[v].erase(find(all(g[v]), u));
		vector<bool> vis(n + 1, false);
		dfs(g, vis, 1);
		if(count(all(vis), true) != n) {
			_++;
		}
		g[u].pb(v);
		g[v].pb(u);
	}
	return _;
}

void SaKaTa() {
	int n, m;
	cin >> n >> m;
	vector<pii> roads;
	FOR(i, 1, m) {
		int u, v;
		cin >> u >> v;
		roads.pb({u, v});
	}
	cout << solve(n, m, roads);
}

int32_t main() {
#define TASKNAME "CAU2"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int testcase = 1;
//    cin >> testcase;
	while(testcase--)
		SaKaTa();
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
