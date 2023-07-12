#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int m, n, k, treemin[N], p[N];

void build(int l, int r, int id) {
	if (l == r) {
		treemin[id] = p[l] ;
		return ;
	}
	int mid = l + r >> 1 ;
	build(l, mid, id * 2) ;
	build(mid + 1, r, id * 2 + 1) ;
	treemin[id] = min(treemin[id * 2], treemin[id * 2 + 1]) ;
}

int getmin(int l, int r, int _l, int _r, int id) {

	if (l > _r || r < _l) return INT_MAX;
	if (l >= _l && r <= _r) return treemin[id] ;
	int mid = l + r >> 1 ;
	return min(getmin(l, mid, _l, _r, id * 2), getmin(mid + 1, r, _l, _r, id * 2 + 1)) ;
}

int32_t main() {
#define TASKNAME "olp_kc21_distance"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> m >> n >> k;
	vector<int> a(m), b(n);
	for(int i = 0; i < m; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	b.pb(-1e18);
	sort(all(b));
	b.pb(1e18);
	b[0] = abs(b[0]);
	for(int i = 0; i < m; i++) {
		auto pos = lower_bound(b.begin() + 1, b.end() - 1, a[i]) - b.begin();
		p[i + 1] = min(abs(b[pos] - a[i]), abs(a[i] - b[pos - 1]));
	}
	//for(int i = 0; i < m; i++) cout << a[i] << '\n';
	build(1, m, 1);
	while(k--) {
		int l, r;
		cin >> l >> r;
		cout << getmin(1, m, l, r, 1) << '\n';
	}
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3 4 3
1 5 7
4 -1 3 9
1 3
1 1
2 2
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
1
2
1
------------------------------    |
==================================+
*/
