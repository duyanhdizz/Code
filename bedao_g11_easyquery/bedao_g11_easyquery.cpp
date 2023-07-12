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
const int N = 9 + 1e5;
const int INF = 1e9;

int n, Node[N * 4], Lazy[4 * N], a[N], q;

void build(int id, int l, int r) {
	if(l == r) {
		Node[id] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	Node[id] = Node[id * 2] + Node[id * 2 + 1];
}
void fix(int id, int l, int r) {
	if(Lazy[id] && l != r) {
		Lazy[id * 2] += Lazy[id];
		Lazy[id * 2 + 1] += Lazy[id];
		int mid = (l + r) >> 1;
		Node[id * 2] += Lazy[id] * (mid - l + 1);
		Node[id * 2 + 1] += Lazy[id] * (r - mid);
		Lazy[id] = 0;
	}
}
int get(int id, int l, int r, int u, int v) {
	fix(id, l, r);
	if(l > v || r < u) {
		return 0;
	}
	if(l >= u && r <= v) {
		return Node[id];
	}
	int mid = (l + r) >> 1;
	return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
void update(int id, int l, int r, int u, int v, int val) {
	if(l > v || r < u) {
		return ;
	}
	if(l >= u && r <= v) {
		Node[id] += val * (r - l + 1);
		Lazy[id] += val;
		return;
	}
	fix(id, l, r);
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, u, v, val);
	update(id * 2 + 1, mid + 1, r, u, v, val);
	Node[id] = Node[id * 2] + Node[id * 2 + 1];
}
struct query {
	int type, l, r, x;
};
vector<query> tvan;
void query2(int i, int mark) {
	if(tvan[i].type == 2) {
		query2(tvan[i].l, -mark);
	} else {
		update(1, 1, n, tvan[i].l, tvan[i].r, mark * tvan[i].x);
	}
}

int32_t main() {
#define TASKNAME "bedao_g11_easyquery"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> q;
	FOR(i, 1, n) cin >> a[i];
	build(1, 1, n);
	tvan.pb({0});
	while(q--) {
		int type;
		cin >> type;
		if(type == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			tvan.pb({type, l, r, x});
		} else {
			if(type == 2) {
				int j;
				cin >> j;
				tvan.pb({type, j});
			} else {
				int l, r;
				cin >> l >> r;
				tvan.pb({type, l, r});
			}
		}
	}
	REP(i, 1, tvan.size()) {
		if(tvan[i].type == 2) {
			query2(i, 1);
		}
		if(tvan[i].type == 1) {
			update(1, 1, n, tvan[i].l, tvan[i].r, tvan[i].x);
		}
		if(tvan[i].type == 3) {
			cout << get(1, 1, n, tvan[i].l, tvan[i].r) << '\n';
		}
	}
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
