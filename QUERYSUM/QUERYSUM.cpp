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

int n, a[N], bit[N];

int getSum(int p) {
	int idx = p, ans = 0;
	while (idx > 0) {
		ans += bit[idx];
		idx -= (idx & (-idx));
	}
	return ans;
}

void update(int u, int v) {
	int idx = u;
	while (idx <= n) {
		bit[idx] += v;
		idx += (idx & (-idx));
	}
}

void SaKaTa() {
	int q;
	cin >> n >> q;
	while(q--) {
		char c;
		cin >> c;
		if(c == 'S') {
			int pos, val;
			cin >> pos >> val;
			update(pos, val - a[pos]);
			a[pos] = val;
		} else {
			int l, r;
			cin >> l >> r;
			cout << getSum(r) - getSum(l - 1) << '\n';
		}
	}
}

int32_t main() {
#define TASKNAME "QUERYSUM"
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
5 6
S 1 1
S 2 2
S 3 3
S 4 4
S 3 1
Q 1 5
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
8
------------------------------    |
==================================+
*/
