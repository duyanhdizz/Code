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

int t;
int i = 1;

void solve() {
	ll l, r;
	cin >> l >> r;
	ll k = 39;
	while(k >= 1) {
		int x = 2;
		while(pow(x, k) <= r) x++;
		if(pow(x - 1, k) >= l && x > 2) {
			cout << "Case #" << i << ":" << ' ' << k << '\n';
			i++;
			return;
		}
		k--;
	}
}

int32_t main() {
#define TASKNAME "power"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> t;
	while(t--)
		solve();
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
4
5 20
10 12
2 100
1000000000000 1000000000000
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
Case #1: 4
Case #2: 1
Case #3: 6
Case #4: 12
------------------------------    |
==================================+
*/
