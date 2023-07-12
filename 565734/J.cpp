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

bool vis[N];
int a[N], ans;
vector<vector<int>> g;

void dfs(int x, int o) {
	if(vis[x]) return;
	vis[x] = true;
	a[x] = o;
	each(y, g[x]) {
		if (!vis[y]) dfs(y, o + 1);
	}
}

void dfs_ (int x, int o) {
	if(vis[x]) return;
	vis[x] = true;
	if (o < a[x]) {
		ans = max(ans, a[x] * 2);
		each(y, g[x]) {
			if (!vis[y]) dfs_(y, o + 1);
		}
	}
}

void SaKaTa() {
	int n, x;
	cin >> n >> x;
	x--;
	g.resize(n);
	FOR(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0, 0);
	memset(vis, false, sizeof vis);
	dfs_(x, 0);
	cout << ans;
}

int32_t main() {
#define TASKNAME "J"
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
