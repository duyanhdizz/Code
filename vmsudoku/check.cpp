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
const int N = 19;
const int INF = 1e9;

int a[N][N];
vector<pii> g[N];

void YeuHuong() {
	FOR(i, 1, 9) {
		FOR(j, 1, 9) {
			cin >> a[i][j];
			g[a[i][j]].pb({i, j});
		}
	}
	int ans = 0;
	FOR(i, 1, 9) {
		int sum_i = 0;
		FOR(j, 0, g[i].size() - 2) {
			FOR(z, j + 1, g[i].size() - 1) {
				sum_i += abs(g[i][z].fi -g[i][j].fi) * abs(g[i][z].se -g[i][j].se);
			}
		}
		ans += sum_i * i;
	}
	ans -= 17000;
	ans = max(ans, 0);
	cout << min(ans, 1062);
}

int32_t main() {
#define TASKNAME "check"
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
		YeuHuong();
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
9 8 4 5 3 1 2 7 6 
2 5 7 6 4 9 1 3 8 
6 1 3 8 2 7 9 4 5 
1 9 6 7 5 3 4 8 2 
8 3 2 4 9 6 7 5 1
7 4 5 2 1 8 6 9 3 
3 7 8 9 6 2 5 1 4
4 2 9 1 8 5 3 6 7
5 6 1 3 7 4 8 2 9
---
1 2 9 8 7 5 6 3 4
6 4 7 1 9 3 8 5 2
8 5 3 2 4 6 9 1 7
9 1 2 4 5 7 3 6 8
7 3 5 6 8 9 2 4 1
4 6 8 3 1 2 5 7 9
2 7 6 9 3 4 1 8 5
3 8 4 5 2 1 7 9 6 
5 9 1 7 6 8 4 2 3
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
493
------------------------------    |
==================================+
*/
