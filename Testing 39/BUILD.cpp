#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e5;
const int INF = 1e9;

struct DSU {
	int n;
	vector<int> par;
	void init(int _n) {
		n = _n;
		par.assign(n, -1);
	}
	int find_par(int x) {
		if(par[x] < 0) return x;
		par[x] = find_par(par[x]);
		return par[x];
	}
	bool unionf(int x, int y) {
		int a = find_par(x), b = find_par(y);
		if(a == b) return 0;
		if(par[a] < par[b]) swap(a, b);
		par[a] += par[b];
		par[b] = a;
		return 1;
	}
};

struct EDGE {
	int u, v, c;
};

int n, res;
pii x[N], y[N];
vector<EDGE> qd;
DSU dsu;

bool cmp(EDGE l, EDGE r) {
	return l.c < r.c;
}

int32_t main() {
#define TASKNAME "BUILD"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	for(int i = 0; i < n; i++) cin >> x[i].fi >> y[i].fi, x[i].se = i, y[i].se = i;
	dsu.init(n);
	sort(x, x + n);
	sort(y, y + n);
	for(int i = 0; i < n - 1; i++) {
		qd.pb({x[i].se, x[i + 1].se, x[i + 1].fi - x[i].fi});
		qd.pb({y[i].se, y[i + 1].se, y[i + 1].fi - y[i].fi});
	}
	sort(all(qd), cmp);
	for(auto& x: qd)
		res += x.c * dsu.unionf(x.u, x.v);
	cout << res;
	return 0;
}
/*
INPUT
5
4 9
9 5
0 2
7 1
3 4
OUTPUT
5
*/
