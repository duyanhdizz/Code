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
const int N = 9 + 1e5;
const int INF = 1e9;

int n, a[N];

namespace sub1 {
	int len = INF, st, fi;
	void main() {
		FOR(i, 2, n) {
			REP(j, 1, i) {
				int gcd = a[j];
				FOR(z, j + 1, i) {
					gcd = __gcd(gcd, a[z]);
				}
				if(gcd == 1) {
					if (len > i - j + 1) {
						len = i - j + 1;
						st = j;
						fi = i;
					}
				}
			}
		}
		if(len == INF) cout << -1;
		else cout << len << " " << st << " " << fi;
	}
}

namespace sub2 {
	int Tree[5 * N], st, fi, len = INF;

	void build (int id, int l, int r) {
		if (l > r) return;
		if (l == r) {
			Tree[id] = a[l];
			return;
		}

		int mid = (l + r) >> 1;
		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);
		Tree[id] = __gcd(Tree[id * 2], Tree[id * 2 + 1]);
	}

	int get(int id, int l, int r, int u, int v) {
		if (v < l || u > r) return 0;
		if (u <= l && r <= v) return Tree[id];

		int mid = (l + r) >> 1;
		return __gcd(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
	}
	void main() {
		build(1, 1, n);
		REP(i, 1, n) {
			int lo = i, hi = n;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				int ans = get(1, 1, n, i, mid);
				if (ans == 1) {
					if (len > mid - i + 1) {
						len = mid - i + 1;
						st = i;
						fi = mid;
					}
					hi = mid - 1;
				} else if (ans > 1) lo = mid + 1;
				else break;
			}
		}

		if (len == INF) cout << -1;
		else cout << len << " " << st << " " << fi;
	}
}

int32_t main() {
#define TASKNAME "fc125_gcdarr"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	if(n <= 1000) sub1::main();
	else sub2::main();
	//sub2::main();
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
5
2
6
12
3
6
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
4 1 4
------------------------------    |
==================================+
*/