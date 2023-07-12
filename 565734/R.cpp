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
const int N = 2106 + 1e6;
const int INF = 2106 + 1e9;

// https://www.youtube.com/watch?v=JqOPBodZmLk

void SaKaTa() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<pii, int>>> g(n);
	FOR(i, 1, m) {
		int x, y, d;
		cin >> x >> y >> d;
		x--, y--;
		g[x].pb({{y, d}, 1});
		g[y].pb({{x, d}, 1});
	}
	FOR(i, 1, k) {
		int s, y;
		cin >> s >> y;
		s--;
		g[0].pb({{s, y}, -1});
		g[s].pb({{0, y}, -1});
	}
	priority_queue<pair<pii, int>> q; // dùng hàng đợi sort đỡ tốn time duyệt
	q.push({{0, 0}, 0}); // {{kc, đỉnh}, trạng thái đường ray (-1) hay con đường (1)}
	vector<int> used(n, 0);
	int _ = 0;
	while(!q.empty()) {
		auto u = q.top();
		int from = u.se; // đỉnh kế tiếp
		int d = u.fi.fi; // trọng số
		q.pop();
		if(used[from] == 1) continue;
		used[from] = 1;
		if (u.fi.se == -1) { // trạng thái khi là dùng ray
			_++;
		}
		each(to, g[from]) {
			q.push({{d - to.fi.se, to.se}, to.fi.fi});
		}
	}
	cout << k - _;
}

int32_t main() {
#define TASKNAME "R"
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
