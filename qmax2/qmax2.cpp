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

int n, k, m, test, ans = 0;
int a[N], f[N] = {};
int h[4 * N], nho[4 * N];

void build(int id, int l, int r) {
	if (l == r) {
		h[id] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);
	h[id] = max(h[2 * id], h[2 * id + 1]);
}

void update(int id, int l, int r, int u, int v, int val) {
	if (v < l || r < u) return;
	if (u <= l  && r <= v) {
		h[id] += val;
		nho[id] += val;
		return;
	}
	int mid = (l + r) / 2;

	int x = nho[id];
	h[2 * id] += x;
	nho[2 * id] += x;
	h[2 * id + 1] += x;
	nho[2 * id + 1] += x;
	nho[id] = 0;

	update(2 * id, l, mid, u, v, val);
	update(2 * id + 1, mid + 1, r, u, v, val);

	h[id] = max(h[2 * id], h[2 * id + 1]);
}

int getmax(int id, int l, int r, int u, int v) {
	if (v < l || r < u) return -INF;
	if (u <= l && r <= v) return h[id];
	int mid = (l + r) / 2;

	int x = nho[id];
	h[2 * id] += x;
	nho[2 * id] += x;
	h[2 * id + 1] += x;
	nho[2 * id + 1] += x;
	nho[id] = 0;

	return max(getmax(2 * id, l, mid, u, v), getmax(2 * id + 1, mid + 1, r, u, v));
}

void SaKaTa() {
	cin >> n;
	build(1, 1, n);
	int q;
	cin >> q;
	while (q--) {
		cin >> k;
		if (k == 0) {
			int x, y, val;
			cin >> x >> y >> val;
			update(1, 1, n, x, y, val);
		} else {
			int x, y;
			cin >> x >> y;
			cout << getmax(1, 1, n, x, y) << '\n';
		}
	}
}

int32_t main() {
#define TASKNAME ""
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
