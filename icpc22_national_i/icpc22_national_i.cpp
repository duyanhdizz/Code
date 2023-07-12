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

int n;

int32_t main() {
#define TASKNAME "icpc22_national_i"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	vector<vector<int>> a(n, vector<int> (n));
	for(auto &x : a) {
		for(auto &xx : x) {
			cin >> xx;
		}
	}
	vector<int> ans(n, 1);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			ans[i] += a[i][j] > a[0][0];
		}
		for(int j = i + 1; j < n; j++) {
			ans[i] += a[i][j] < a[0][0];
		}
	}
	for(auto i : ans) cout << i << ' ' ;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
2
0 1
1 0
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
1 2
------------------------------    |
==================================+
*/
