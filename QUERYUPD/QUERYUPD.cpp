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

int n, bit[N], a[N];

void updatePoint(int u, int v) {
	int idx = u;
	while (idx <= n) {
		bit[idx] += v;
		idx += (idx & (-idx));
	}
}

void updateRange(int l, int r, int v) {
	updatePoint(l, v);
	updatePoint(r + 1, -v);
}

int get(int u) {
	int idx = u, ans = 0;
	while (idx > 0) {
		ans += bit[idx];
		idx -= (idx & (-idx));
	}
	return ans;
}

void SaKaTa() {
	int q;
	cin >> n >> q;
	FOR(i, 1, q) {
		char c;
		cin >> c;
		if(c == 'I') {
			int l, r, x;
			cin >> l >> r >> x;
			updateRange(l, r, x);
		} else {
			int i;
			cin >> i;
			cout << get(i) << '\n';
		}
	}
}

int32_t main() {
#define TASKNAME "QUERYUPD"
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
5 7
I 1 3 1
I 2 5 2
Q 4
I 3 4 3
I 1 1 4
I 5 5 5
Q 5
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
2
7
------------------------------    |
==================================+
*/
