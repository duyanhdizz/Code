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

int n, m, d;

int32_t main() {
#define TASKNAME ""
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> d >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		if (y < x - d || y < -x + d || y > x + d || y > -x + 2*n - d) {
			cout << "NO";
		} else cout << "YES";
		cout << '\n';
	}
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
7 2
4
2 4
4 1
6 3
4 5
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
YES
NO
NO
YES
------------------------------    |
==================================+
*/
