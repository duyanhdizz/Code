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

int n, m;

int32_t main() {
#define TASKNAME "364577G"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m;
	int res = INF;
	while(m--) {
		int l, r;
		cin >> l >> r;
		res = min(res, r - l + 1);
	}
	cout << res << '\n';
	for(int i = 0; i < n; i++) cout << (i + 1) % res << ' ';
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
5 3
1 3
2 5
4 5
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
2
1 0 1 0 1
------------------------------    |
==================================+
*/
