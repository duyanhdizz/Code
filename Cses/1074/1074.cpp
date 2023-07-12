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

int n, a[N];
ll dp[N];

int32_t main() {
#define TASKNAME "2183"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	dp[0] = 1;
	for(int i = 1; i <= n; i++) {
		if (dp[i - 1] < a[i]) return cout << dp[i - 1], 0;
		dp[i] = dp[i - 1] + a[i];
	}
	cout << dp[n];
	return 0;
}
/*
INPUT
5
2 9 1 2 7
OUTPUT
6
*/
