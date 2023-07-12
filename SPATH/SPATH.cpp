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

int s, t, dis[N];
int _ = 1e18;
bool vis[N];
vector<tuple<int, int, int>> g;

void SaKaTa() {
	int n, m;
	cin >> n >> m >> s >> t;
	s--;
	t--;
	while(m--) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		g.pb(make_tuple(u, v, w));
		g.pb(make_tuple(v, u, w));
	}
	FOR(i, 0, n - 1) dis[i] = 1e18;
	dis[s] = 0;
	FOR(i, 1, n - 1) {
		each(e, g) {
			int a, b, w;
			tie(a, b, w) = e;
			dis[b] = min(dis[b], dis[a] + w);
		}
	}
	cout << dis[t];
}

int32_t main() {
#define TASKNAME "SPATH"
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
