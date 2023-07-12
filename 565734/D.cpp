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

vector<vector<int>> adj;
vector<int> vis;

void dfs(int x) {
	if(vis[x]) return;
	vis[x] = 1;
	each(y, adj[x]) {
		dfs(y);
	}
}

void SaKaTa() {
	int n, m;
	cin >> n >> m;
	adj.resize(n);
	FOR(i, 1, m) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vis.resize(n);
	int _ = 0;
	FOR(i, 0, n - 1) {
		if (!vis[i]) {
			_++;
			dfs(i);
		}
	}
	cout << _;
}

int32_t main() {
#define TASKNAME "D"
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
4 6
1 2
1 3
1 4
2 3
2 4
3 4
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
1
------------------------------    |
==================================+
*/
