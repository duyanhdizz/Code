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
const int N = 2106 + 1e5;
const int INF = 2106 + 1e9;

int n, m, ans = 0;
int a[N];
bool vis[N];
vector<vector<int>> g;

struct item {
	int best, cnt;
} _[N];

void dfs(int u) {
	vis[u] = true;
	if (a[u]) {
		_[u].cnt++;
		_[u].best = max(_[u].best, _[u].cnt);
	} else {
		_[u].cnt = 0;
	}
	int __ = 0;
	each(v, g[u]) {
		if (vis[v]) continue;
		_[v] = _[u];
		dfs(v);
		__++;
	}
	if (__ == 0 && _[u].best <= m) ans++;
}

void SaKaTa() {
	cin >> n >> m;
	FOR(i, 0, n - 1) cin >> a[i];
	g.resize(n);
	FOR(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);
	cout << ans;
}

int32_t main() {
#define TASKNAME "F"
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
4 1
1 1 0 0
1 2
1 3
1 4
-------
7 1
1 0 1 1 0 0 0
1 2
1 3
2 4
2 5
3 6
3 7
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
2
-------
2
------------------------------    |
==================================+
*/
