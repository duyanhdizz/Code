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

int up[N], down[N];

void compress(vector<int> &a) {
	set<int> s(a.begin(), a.end());
	vector<int> b(s.begin(), s.end());
	for (int &x: a) {
		x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
	}
}

struct Fenwick {
	int n;
	vector<int> f;
	Fenwick(int n): n(n), f(n+1, 0) {}
	void set(int x, int i) {
		for (; i<=n; i += i&(-i)) f[i] = max(f[i], x);
	}
	int get(int i) const {
		int r = 0;
		for (; i>=1; i -= i&(-i)) r = max(r, f[i]);
		return r;
	}
};

int32_t main() {
#define TASKNAME "LSSLEN"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	compress(a);

	Fenwick Bit(n);
	for (int x: a) Bit.set(Bit.get(x-1) + 1, x);
	int tang = Bit.get(n);
	FOR(i, 1, n) up[i] = Bit.get(i);
	reverse(all(a));
	compress(a);

	Fenwick Bit_t(n);
	for (int x: a) Bit_t.set(Bit_t.get(x-1) + 1, x);
	int giam = Bit_t.get(n);
	FOR(i, 1, n) down[i] = Bit_t.get(i);
	int mid = 1;
	FOR(i, 1, n) cerr << up[i] << ' ';
	cerr << '\n';
	FOR(i, 1, n) cerr << down[n - i + 1] << ' ';
	FOR(i, 1, n) mid = max(mid, up[i] + down[n - i + 1] - 1);
	cout << max({mid, tang, giam});
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