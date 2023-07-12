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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), v;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(i % 2 == 0) v.pb(a[i]);
	}
	v.pb(INF);
	for(int i = 0; i < v.size(); i++) {
		if(v[i] < v[i + 1]) {
			cout << i * 2 << '\n';
			return;
		}
	}
}

int32_t main() {
#define TASKNAME "dtl22_b"
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
5
3
3 2 2
4
3 1 4 2
7
5 4 3 2 3 2 2
10
10 9 8 7 6 5 4 3 2 1
11
11 10 9 8 7 6 5 4 3 2 1
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
2
0
6
8
10
------------------------------    |
==================================+
*/
