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

void SaKaTa() {
	int n, m;
	cin >> n >> m;
	vector<vector<pii>> adj(n);
	FOR(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	vector<ll> dis(n, -1);
	vector<int> pre(n, -1);
	priority_queue<tuple<ll, int, int>> h;
	h.emplace(0, 0, -1);
	while (!h.empty()) {
		auto [d, x, t] = h.top();
		h.pop();
		if (dis[x] != -1) {
			continue;
		}
		dis[x] = -d;
		pre[x] = t;
		for(auto [y, w] : adj[x]) {
			h.emplace(d - w, y, x);
		}
	}
	if (dis[n - 1] == -1) {
		cout << -1 << "\n";
		return;
	}
	vector<int> a;
	for (int x = n - 1; x != -1; x = pre[x]) {
		a.pb(x);
	}
	reverse(all(a));
	for (auto x : a) {
		cout << x + 1 << " \n"[x == n - 1];
	}
}

int32_t main() {
#define TASKNAME "P"
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
