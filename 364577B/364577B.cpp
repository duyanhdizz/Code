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

int n, a[N], b[N];
map<int, int> m;

int32_t main() {
#define TASKNAME "364577B"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		m[b[i]] = i + 1;
	}
	int res = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(m[a[i]] > ans) ans = m[a[i]];
		else res++;
	}
	cout << res;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
7
5 2 3 6 7 1 4
2 3 6 7 1 4 5
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
6
------------------------------    |
==================================+
*/
