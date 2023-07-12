#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int n, k, a[N], m[N][2];

int32_t main() {
#define TASKNAME "bedao_r12_bfriday"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		m[i % k][a & 1]++;
	}
	int ans = 0;
	for(int i = 0; i < k; i++) {
		if(m[i][0] < m[i][1]) ans += m[i][0];
		else ans += m[i][1];
	}
	cout << ans;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
5 3
1 10 1 2 9
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
2
------------------------------    |
==================================+
*/