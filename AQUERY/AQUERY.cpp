#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define REP(i, a, b) for (int i = (a); i < (int) (b); ++i)
#define each(a, x) for (auto &a : x)
#define fi first
#define se second
#define pb push_back
#define int long long
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e5;
const int INF = 1e9;

int n, q;
ll a[N];
pair<ll, ll> t[N * 4];
ll lazy[N * 4];

void push(int node, int l, int r) {
	int &x = t[node].fi;
	if (x != -1) {
		int m = (l + r) / 2;
		t[node * 2].fi = t[node * 2 + 1].fi = x;
		t[2 * node].se = (m - l + 1) * x;
		t[2 * node + 1].se = (r - m) * x;
		x = -1;
	}
}

void update(int node, int l, int r, int u, int v, int val) {
	if (l > v || r < u) return;
	if (l >= u && r <= v) {
		t[node].fi = val;
		t[node].se = (r - l + 1) * val;
		return;
	}
	push(node, l, r);
	int m = (l + r) / 2;
	update(node * 2, l, m, u, v, val);
	update(node * 2 + 1, m + 1, r, u, v, val);
	t[node].se = t[node * 2].se + t[node * 2 + 1].se;
}


ll sum(int node, int l, int r, int u, int v) {
	if (l > v || r < u) return 0;
	if (l >= u && r <= v) return t[node].se;
	push(node, l, r);
	int mid = (l + r) / 2;
	return sum(node * 2, l, mid, u, v) + sum(node * 2 + 1, mid + 1, r, u, v);
}

void SaKaTa() {
	cin >> n >> q;
	for(int i = 0; i <= 4 * n + 1; i ++) t[i] = {-1, 0};
	while (q --) {
		int r, p;
		cin >> r >> p;
		int dau = 1, cuoi = r;
		int tmp = r;
		while (dau <= cuoi) {
			int mid = (dau + cuoi) / 2;
			int amid = sum(1, 1, n, mid, mid);
			int t = (r - mid + 1) * amid - sum(1, 1, n, mid, r);
			if (t <= p) {
				cuoi = mid - 1;
				tmp = mid;
			} else dau = mid + 1;
		}
		int al = sum(1, 1, n, tmp, tmp);
		int t = (r - tmp + 1) * al - sum(1, 1, n, tmp, r);
		p -= t;
		int anew = al + p / (r - tmp + 1);
		int pos = tmp + p % (r - tmp + 1) - 1;
		update(1, 1, n, tmp, pos, anew + 1);
		update(1, 1, n, pos + 1, r, anew);
	}
	for(int i = 1; i <= n; i ++) cout << sum(1, 1, n, i, i) << " ";
}

int32_t main() {
#define TASKNAME "AQUERY"
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
