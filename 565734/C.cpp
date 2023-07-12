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

vector<int> vis;
vector<vector<int>> g;
int _ = 0;
bool check = true;

void dfs(int x) {
	if(check == false) return; /// return ngay tu khi gap ans = 1e6
	if(vis[x]) return;
	_++;
	if(_ == 1e6 && check == true) {
		cout << _;
		check = false;
		return;
	}
	vis[x] = 1;
	each(y, g[x]) {
		dfs(y);
	}
	vis[x] = 0; /// mau chot
}

void SaKaTa() {
	int n, m;
	cin >> n >> m;
	g.resize(n);
	FOR(i, 1, m) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	vis.resize(n);
	dfs(0);
	if(check == true) cout << _;
}

int32_t main() {
#define TASKNAME "C"
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
4 2
1 2
2 3
----
8 21
2 6
1 3
5 6
3 8
3 6
4 7
4 6
3 4
1 5
2 4
1 2
2 7
1 4
3 5
2 5
2 3
4 5
3 7
6 7
5 7
2 8
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
3
----
2023
Fail output = 8 :<
vis[x] sau up = 0
------------------------------    |
==================================+
*/
