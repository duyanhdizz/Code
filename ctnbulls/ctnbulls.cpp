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
const int N = 9 + 1e5;
const int INF = 1e9;
const int MOD = 2111992;

int n, k, dp[N];

int32_t main() {
#define TASKNAME "ctnbulls"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		if(i >= k + 2) {
			dp[i] = (dp[i - 1] + dp[i - k - 1]) % MOD;
		} else {
			dp[i] = (i + 1) % MOD;
		}
	}
	cout << dp[n];
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
4 2
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
6
------------------------------    |
==================================+
*/