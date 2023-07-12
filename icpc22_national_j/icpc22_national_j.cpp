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

int32_t main() {
#define TASKNAME "icpc22_national_j"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n), b(m);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				int x;
				cin >> x;
				a[i].pb(x);
				b[j].pb(x);
			}
		}
		for(int i = 0; i < n; i++) sort(all(a[i]));
		for(int i = 0; i < m; i++) sort(all(b[i]));
		int res = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(a[i][0] == a[i].back() && b[j][0] == b[j].back()) res++;
			}
		}
		cout << res << '\n';
	}
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3
1 1
10
2 3
2 5 2
2 2 2
3 3
1 1 1
1 1 1
1 1 1
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
1
2
9
------------------------------    |
==================================+
*/
