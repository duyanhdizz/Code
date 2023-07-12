#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast","unroll-loops")
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

int n, a[N], treemax[N << 2], treemin[N << 2];

void build(int l, int r, int id) {

	if (l == r) {
		treemax[id] = a[l] ;
		treemin[id] = a[l] ;
		return ;
	}
	int mid = l + r >> 1 ;
	build(l, mid, id * 2) ;
	build(mid + 1, r, id * 2 + 1) ;
	treemax[id] = max(treemax[id * 2], treemax[id * 2 + 1]) ;
	treemin[id] = min(treemin[id * 2], treemin[id * 2 + 1]) ;
}

int getmax(int l, int r, int _l, int _r, int id) {

	if (l > _r || r < _l) return INT_MIN ;
	if (l >= _l && r <= _r) return treemax[id] ;
	int mid = l + r >> 1 ;
	return max(getmax(l, mid, _l, _r, id * 2), getmax(mid + 1, r, _l, _r, id * 2 + 1));
}

int getmin(int l, int r, int _l, int _r, int id) {

	if (l > _r || r < _l) return INT_MAX ;
	if (l >= _l && r <= _r) return treemin[id] ;
	int mid = l + r >> 1 ;
	return min(getmin(l, mid, _l, _r, id * 2), getmin(mid + 1, r, _l, _r, id * 2 + 1)) ;
}

int32_t main() {
#define TASKNAME "2022thtc2b3"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	build(1, n, 1);
	int ans = -INF;
	FOR(i, 2, n - 1) {
		ans = max(ans, 3 * getmax(1, n, 1, i - 1, 1) + 2 * a[i] - 5 * getmin(1, n, i + 1, n, 1));
	}
	cout << ans;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
10
4 9 7 9 4 3 2 9 15 6
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
35
------------------------------    |
==================================+
*/
