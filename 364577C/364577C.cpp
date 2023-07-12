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
const int N = 9 + 1e6;
const int INF = 1e9;

int n, k, q, a[N], cnt[N];

void solve() {
	int l, r;
	cin >> l >> r;
	cout << cnt[r] - cnt[l - 1] << '\n';
}

int32_t main() {
#define TASKNAME "364577C"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> k >> q;
	for(int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		a[x]++;
		a[y + 1]--;
	}
	int r = 0;
	for(int i = 1; i <= N; i++) {
		r += a[i];
		if(r >= k) cnt[i]++;
		cnt[i] += cnt[i - 1];
	}
	while(q--) solve();
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3 2 4
91 94
92 97
97 99
92 94
93 97
95 96
90 100
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
3
3
0
4
------------------------------    |
==================================+
*/
