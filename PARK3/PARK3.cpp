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
const int N = 9 + 2e5;
const int INF = 1e9;

int n, m;
vector<int> g[63 + N];
unordered_map<int, int> cnt;

int32_t main() {
#define TASKNAME "PARK3"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m;
	FOR(i, 1, m) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	// xuat phat tu bai so 1
	REP(i, 0, g[1].size()) {
		cerr << g[1][i] << '\n';
		REP(j, 0, g[g[1][i]].size()) {
			cnt[g[g[1][i]][j]]++;
		}
	}
	ll ans = 0;
	FOR(i, 2, n) ans += cnt[i] * (cnt[i] - 1);
	cout << ans;
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
10 14
1 5
2 5
5 6
2 3
1 3
2 4
4 6
1 6
1 7
7 8
8 1
1 10
9 10
9 8
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
4
------------------------------    |
==================================+
*/
